#include "linked_list.h"
#include <stdexcept>
#include <iostream>

void print(LinkedList* linkedList);
int main() {

	LinkedList* list = new LinkedList();

	list->push_front(10);
	//print(list);

	list->insert(0, 100);
	print(list);

	list->insert(2, 50);
	print(list);

	list->insert(1, 20);
	print(list);

	list->push_back(1000);
	print(list);

	list->erase(0);
	print(list);

	list->erase(1);
	print(list);

	list->insert(list->get_node(0), 0);
	print(list);

	list->insert(list->get_node(2), 2);
	print(list);

	std::cout << list->get(2);
	std::cout << "\n";

	list->sort();
	print(list);

	int i = list->front();
	std::cout << i;

	std::cout << "\n";

	i = list->back();
	std::cout << i;

	list->erase(list->get_node(1));
	print(list);

	list->clear();

	list = LinkedList::create_from_array(new int[4]{ 1,5,3,4 }, 4);
	print(list);
	system("pause");
}




LinkedList::Node * LinkedList::get_node(int index)
{
	if (index < 0 && index >=(size - 1)) {
		throw std::out_of_range("Not correct index!");
	}
	Node* node = head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	return node;
}

LinkedList * LinkedList::create_from_array(int * source, int size)
{
	LinkedList* linklist = new LinkedList();
	for (int i = 0; i < size; i++) {
		linklist->push_back(source[i]);
	}

	return linklist;

}

LinkedList::~LinkedList()
{

}

int LinkedList::get(int index)
{

	if (index < 0 && index >=(size - 1)) {
		throw std::out_of_range("Not correct index!");
	}
	Node* node = head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	return node->value;
}

int LinkedList::front()
{
	if (size == 0) {
		throw std::logic_error("The list is empty!");
	}
	return head->value;
}

int LinkedList::back()
{
	if (size == 0) {
		throw std::logic_error("The list is empty!");
	}
	return tail->value;
}

void LinkedList::push_back(int value)
{
	Node* node = new Node(value);
	size == 0 ? head = node : tail->next = node, node->prev = tail;
	tail = node;
	size++;
}

void LinkedList::push_front(int value)
{
	Node* node = new Node(value);
	Node* tmp = head;
	head = node;
	head->next = tmp;

	size == 0 ? tail = head : tmp->prev = head;

	size++;


}

void LinkedList::pop_back()
{
	if (size == 0) {
		throw std::logic_error("The list is empty!");
	}
	if (size != 0) {
		size == 1 ? head = nullptr : tail->prev->next = nullptr, tail = tail->prev;
	}
	size--;
}

void LinkedList::pop_front()
{
	if (size == 0) {
		throw std::logic_error("The list is empty!");
	}
	if (size != 0) { head = head->next; size--; }

	size == 0 ? tail = nullptr : head->prev = nullptr;
}


void LinkedList::insert(int index, int value)
{
	if (index < 0 && index >=(size - 1)) {
		throw std::out_of_range("Not correct index!");
	}
	Node* node = new Node(value);
	if (index == 0) {
		push_front(value);
	}
	else if (index == size) {
		push_back(value);
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i != index; i++) {
			temp = temp->next;
		}

		node->prev = temp->prev;
		node->next = temp;
		temp->prev->next = node;
		temp->prev = node;
		size++;
	}
	return;
}

void LinkedList::erase(int index)
{
	if (index < 0 && index >= (size-1)) {
		throw std::out_of_range("Not correct index!");
	}

	Node* node = get_node(index);
	erase(node);
}

void LinkedList::insert(Node * prev, int value)
{
	Node*node = head;
	int count = 0;
	while (node != prev->next) {
		node = node->next;
		count++;
	}
	insert(count, value);
}

void LinkedList::erase(Node * node)
{
	if (node == head) {

		pop_front();
	}
	else if (node == tail)
	{
		pop_back();
	}
	else 
	{
		Node* temp = node;
		(temp->prev)->next = node->next;
		(temp->next)->prev = node->prev;

		size--;
	}
}

int LinkedList::get_size()
{
	return size;
}

bool LinkedList::empty()
{
	bool res;
	size == 0 ? res = true : res = false;
	return res;
}

void LinkedList::clear()
{
	while (size != 0) {
		pop_back();
	}
}

void LinkedList::sort()
{
	Node* current = head;
	while (current->next) {
		if ((current->value) > (current->next->value)) {
			int tmp = current->next->value;
			current->next->value = current->value;
			current->value = tmp;

			current = current->next;
			sort();
		}
		else
		{
			current = current->next;
		}
	}
}

int LinkedList::find_first(int value)
{
	Node* node = head;
	int count = 0;
	while (node->value != value) {
		node = node->next;
		count++;
		if (count >= size) {
			return size - 1;
			break;
		}
	}
	return count;
}


void print(LinkedList* linkedList) {
	int size = linkedList->get_size();
	for (int i = 0; i < size; ++i) {
		std::cout << linkedList->get(i);
		std::cout << " ";
	}
	std::cout << "\n";
}