#pragma once

#include <vector>
#include <map>

class Compressor
{
public:
	struct Node
	{

		/*Pointers to left and right elements and branches */
		Node *left = nullptr, *right = nullptr;

		/*Symbol that is stored in current node*/
		char32_t symbol = -1;

		Node(){}

		/* Constructor of the node element with params: char32_t symbol*/
		Node(char32_t symbol) : symbol(symbol) {}
	};

	/*Bytes from file which are stored in vector<char>*/
	std::vector<char> in_bytes;

	/*Bytes which we put in file*/
	std::vector<char> out_bytes;

	/*Byte index in vector in_bytes*/
	int in_index;

	/*Byte index in vector out_bytes*/
	int out_index = 0;

	/*Tree root that is stored Huff or Shan tree*/
	Node* tree_root;

	/*Table of codes (symbol<->symbol's code)*/
	std::map<char32_t, std::vector<int>> codes_table;

public:

	/*Read file in binary mode and put bytes in vector<char> in_bytes*/
	void read_file(std::string file);

	/*Read bit*/
	int read_bit();

	/*Read byte*/
	int read_byte();

	int read_least6();

	/*Read char32_t symbol*/
	char32_t read_symbol();

	/*Write bit in out_bytes vector*/
	void write_bit(int bit);

	/*Write byte in out_bytes vector*/
	void write_byte(int byte);

	/*Write char32_t in out_bytes vector*/
	void write_symbol(char32_t value);

	/*Write out_bytes vector in file*/
	void save(std::string file);

	/*Table of frequencies*/
	std::map<char32_t, int> make_frequencies_table();

	/*Method makes Huffman tree*/
	void make_huffman_tree(std::map<char32_t, int>& table);

	/*Method splits nodes for making Shannon-Fano tree*/
	Node* recursive_split(std::pair<int, Node*>* left, std::pair<int, Node*>* right);

	/*Method makes Shannon-Fano tree*/
	void make_shannon_tree(std::map<char32_t, int>& table);

	/*Method makes Table of codes (symbol<->symbol's code)*/
	void make_codes_table(std::vector<int>& code, Node* node);

	/*Methods write tree in vector out_bytes(to file)*/
	void write_node(Node* node);
	void write_leafs(Node* node);

	/*Methods read tree from vector in_bytes (from file)*/
	Node* read_node();
	void read_leafs(Node* node);

	/*Main method for compressing that takes two params:1)the path to the file 2)Method of compressing(Huffman or Shannon-Fano)*/
	void go_compress(std::string input, std::string method);

	/*Main method for decompressing that takes two params:1)the path to the file 2)Method of decompressing(h or s)*/
	void go_decompress(std::string input, std::string method);
};

