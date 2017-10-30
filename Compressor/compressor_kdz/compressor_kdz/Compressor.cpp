#include "Compressor.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>

void Compressor::read_file(std::string file)
{
	in_index = 0;
	in_bytes.clear();
	std::ifstream in(file, std::ios::binary);
	int ch;
	while ((ch = in.get()) != std::char_traits<char>::eof())
		in_bytes.push_back(ch);
}

int Compressor::read_bit()
{
	int bit = (in_bytes[in_index / 8] >> (in_index % 8)) & 1;
	in_index++;
	return bit;
}

int Compressor::read_byte()
{
	int byte = 0;
	for (int i = 0; i < 8; i++)
		byte += read_bit() << i;
	return byte;
}

int Compressor::read_least6()
{
	return read_byte() & 0b111111;
}

char32_t Compressor::read_symbol()
{
	int b0 = read_byte();
	if (b0 >> 7 == 0)
		return b0;
	if (b0 >> 5 == 0b110)
		return (b0 & 0b11111) << 6 | read_least6();
	if (b0 >> 4 == 0b1110)
		return (b0 & 0b1111) << 12 | read_least6() << 6 | read_least6();
	if (b0 >> 3 == 0b11110)
		return (b0 & 0b111) << 18 | read_least6() << 12 | read_least6() << 6 | read_least6();

	return INT32_MAX;
}

void Compressor::write_bit(int bit)
{
	int byte_index = out_index / 8;
	int bit_index = out_index % 8;

	if (byte_index >= out_bytes.size())
		out_bytes.push_back(0);

	out_bytes[byte_index] += bit << bit_index;

	out_index++;
}

void Compressor::write_byte(int byte)
{
	for (int i = 0; i < 8; i++)
		write_bit((byte >> i) & 1);
}

void Compressor::write_symbol(char32_t value)
{
	if (value < 0x0080)
	{
		write_byte(value);
	}
	else if (value < 0x0800)
	{
		write_byte(0b110 << 5 | value >> 6);
		write_byte(0b10 << 6 | value & 0b111111);
	}
	else if (value < 0x10000)
	{
		write_byte(0b1110 << 4 | value >> 12);
		write_byte(0b10 << 6 | (value >> 6) & 0b111111);
		write_byte(0b10 << 6 | value & 0b111111);
	}
	else
	{
		write_byte(0b11110 << 3 | value >> 18);
		write_byte(0b10 << 6 | (value >> 12) & 0b111111);
		write_byte(0b10 << 6 | (value >> 6) & 0b111111);
		write_byte(0b10 << 6 | value & 0b111111);
	}
}

void Compressor::save(std::string file)
{
	std::ofstream out(file, std::ios::binary);
	for (char byte : out_bytes)
		out.put(byte);
	out_bytes.clear();
	out_index = 0;
}

std::map<char32_t, int> Compressor::make_frequencies_table()
{
	std::map<char32_t, int> table;
	while (in_index / 8 < in_bytes.size())
		table.insert(std::make_pair(read_symbol(), 0)).first->second++;
	return table;
}

void Compressor::make_huffman_tree(std::map<char32_t, int>& table)
{
	std::multimap<int, Node*> tree_table;
	for (std::map<char32_t, int>::iterator i = table.begin(); i != table.end(); ++i)
		tree_table.insert(std::make_pair(i->second, new Node(i->first)));

	while (tree_table.size() > 1)
	{
		Node* node = new Node();
		node->left = tree_table.begin()->second;
		int node_frequency = tree_table.begin()->first;
		tree_table.erase(tree_table.begin());
		node->right = tree_table.begin()->second;
		node_frequency += tree_table.begin()->first;
		tree_table.erase(tree_table.begin());
		tree_table.insert(std::make_pair(node_frequency, node));
	}

	tree_root = tree_table.begin()->second;
}

Compressor::Node* Compressor::recursive_split(std::pair<int, Node*>* left, std::pair<int, Node*>* right)
{
	if (left == right - 1)
		return left->second;

	int sum = 0;
	for (std::pair<int, Node*>* i = left; i < right; ++i)
		sum += i->first;

	int half_sum = 0;
	std::pair<int, Node*>* new_right = left;
	while (abs(half_sum + new_right->first - sum / 2) < abs(half_sum - sum / 2))
	{
		half_sum += new_right->first;
		new_right++;
	}

	Node* node = new Node();
	node->left = recursive_split(left, new_right);
	node->right = recursive_split(new_right, right);
	return node;
}

void Compressor::make_shannon_tree(std::map<char32_t, int>& table)
{
	std::pair<int, Node*>* nodes = new std::pair<int, Node*>[table.size()];

	int node_index = 0;
	for (std::map<char32_t, int>::iterator i = table.begin(); i != table.end(); ++i)
		nodes[node_index++] = std::make_pair(i->second, new Node(i->first));

	std::sort(nodes, nodes + table.size(), [](std::pair<int, Node*> left, std::pair<int, Node*> right)
	{
		return left.first > right.first;
	});

	tree_root = recursive_split(nodes, nodes + table.size());
	delete[] nodes;
}

void Compressor::make_codes_table(std::vector<int>& code, Node* node)
{
	if (node->symbol == -1)
	{
		code.push_back(0);
		make_codes_table(code, node->left);
		code[code.size() - 1] = 1;
		make_codes_table(code, node->right);
		code.pop_back();
	}
	else
	{
		codes_table.insert(std::make_pair(node->symbol, code));
	}
}

void Compressor::write_node(Node* node)
{
	if (node->symbol != -1)
		write_bit(0);
	else
	{
		write_bit(1);
		write_node(node->left);
		write_node(node->right);
	}
}


void Compressor::write_leafs(Node* node)
{
	if (node->symbol != -1)
		write_symbol(node->symbol);
	else
	{
		write_leafs(node->left);
		write_leafs(node->right);
	}
}

Compressor::Node* Compressor::read_node()
{
	if (read_bit() == 0)
		return new Node(-2);
	else
	{
		Node* node = new Node();
		node->left = read_node();
		node->right = read_node();
		return node;
	}
}

void Compressor::read_leafs(Node* node)
{
	if (node->symbol == -2)
		node->symbol = read_symbol();
	else
	{
		read_leafs(node->left);
		read_leafs(node->right);
	}
}

void Compressor::go_compress(std::string input, std::string method)
{
	read_file(input + ".txt");
	std::map<char32_t, int> frequencies_table = make_frequencies_table();

	if (method == "h") {
		make_huffman_tree(frequencies_table);
	}
	else if (method == "s") {
		make_shannon_tree(frequencies_table);
	}
	else
	{
		std::cout << "ћетод h или s не был выбран!";
		return;
	}
	std::vector<int> codes;
	make_codes_table(codes, tree_root);

	int symbols_count = 0;
	for (std::map<char32_t, int>::iterator i = frequencies_table.begin(); i != frequencies_table.end(); ++i)
		symbols_count += i->second;

	for (int i = 0; i < sizeof(int) * 8; i++)
		write_bit((symbols_count >> i) & 1);

	write_node(tree_root);
	write_leafs(tree_root);

	in_index = 0;
	while (in_index / 8 < in_bytes.size())
		for (int bit : codes_table[read_symbol()])
			write_bit(bit);
	if (method == "h") {
		save(input + ".haff");
	}
	else {
		save(input + ".shan");
	}
}

void Compressor::go_decompress(std::string input, std::string method)
{
	if (method == "h") {
		read_file(input + ".haff");
	}
	else if (method == "s") {
		read_file(input + ".shan");
	}
	else {
		std::cout << "ћетод dh или ds не был выбран! ";
		return;
	}
	int symbols_count = 0;
	for (int i = 0; i < sizeof(int) * 8; i++)
		symbols_count += read_bit() << i;

	tree_root = read_node();
	read_leafs(tree_root);

	codes_table.clear();
	std::vector<int> codes;
	make_codes_table(codes, tree_root);

	while (symbols_count-- > 0)
	{
		Node* node = tree_root;
		while (node->symbol == -1)
			node = read_bit() ? node->right : node->left;
		write_symbol(node->symbol);
	}
	if (method == "h") {
		save(input + "-unz-h.txt");
	}
	else {
		save(input + "-unz-s.txt");
	}

}
