#ifndef BINARY_TREE_BINARY_TREE_CPP 
#define BINARY_TREE_BINARY_TREE_CPP 
#include "binary_tree.h"
#include <stdexcept>

template<class T>
void BinaryTree<T>::insert(int key, T value) 
{
	Node* node = head;
	Node* temp = nullptr;
	while (node != nullptr) {
		if (key == node->key) {
			std::logic_error("Key has already added!");
		}
		else
		{
			temp = node;
			key < node->key ? node = node->left : node = node->right;

		}

	}

	 Node* newnode= new Node(key, value);
	if (temp == nullptr) {
		head = newnode;
	}
	else
	{
		key < temp->key ? temp->left = newnode : temp->right = newnode;
	}
	size++;
}

template<class T>
void BinaryTree<T>::remove(int key)
{
	Node* node = head;
	Node* temp = nullptr;
	while (node != nullptr) {
		if (key == node->key) {
			break;
		}
		else
		{
			temp = node;
			key < node->key ? node = node->left : node = node->right;
		}
	}

	if (node == nullptr) {
		throw std::logic_error("Key doesnt exist!");
	}

	if (node->right == nullptr) {
		if (temp == nullptr) {
			head = node->left;
		}
		else
		{
			node == temp->left ? temp->left = node->left : temp->right = node->left;

		}
	}
	else
	{

		Node* theMostLeft = node->right;
		temp = nullptr;
		while (theMostLeft->left != nullptr) {
			temp = theMostLeft;
			theMostLeft = theMostLeft->left;
		}


		temp != nullptr ? temp->left = theMostLeft->right : node->right = theMostLeft->right;
		node->key = theMostLeft->key;
		node->value = theMostLeft->value;
	}


	size--;

}

template<class T>
T BinaryTree<T>::find(int key)
{
	Node* node = head;
	while (node != nullptr) {
		if (key == node->key) {
			return node->value;
		}
		key < node->key ? node = node->left : node = node->right;
	 }
	throw std::logic_error("Key doesnt exist!");	
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	while (head != nullptr) {
		remove(head->key);
	}
}

template<class T>
void BinaryTree<T>::TraverseNode(Node * start, T(*func)(T))
{
	if (start != nullptr) {
		TraverseNode(start->left,func);
		start->value = func(start->value);
		TraverseNode(start->right, func);
	}
}


#endif
