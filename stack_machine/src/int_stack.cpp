////////////////////////////////////////////////////////////////////////////////
// Module Name:  int_stack.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "int_stack.h"
#include <stdexcept>

// TODO: add necessary headers here
// #include <...

namespace xi {



// TODO: add method definitions here



	IntStack::IntStack(size_t sz)
	{
		_ssize = sz;
		_head = 0;
		_stack = new int[sz];
	}

	IntStack::~IntStack()
	{
		delete[]_stack;
	}

	void IntStack::push(int el)
	{
		if (isFull()) throw std::logic_error("Stack is full!");
		_stack[_head++] = el;
	}

	int IntStack::pop()
	{
		if (isEmpty()) throw std::logic_error("Stack is empty, nothing to delete!");
		return _stack[--_head];
	}

	int IntStack::top()
	{
		return _stack[_head - 1];
	}

	void IntStack::clear()
	{
		_head = 0;
	}

	bool IntStack::isEmpty() const
	{
		if (_head == 0)
		{
			return true;
		}
		return false;
	}

	bool IntStack::isFull() const
	{
		if (_head == _ssize) 
		{
			return true;
		}
		return false;
	}

} // namespace xi