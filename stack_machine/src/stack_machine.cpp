////////////////////////////////////////////////////////////////////////////////
// Module Name:  stack_machine.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include "stack_machine.h"

// TODO: add necessary headers here
#include <ctype.h>


namespace xi {

//==============================================================================
// Free functions -- helpers
//==============================================================================

// TODO: if you need some free function, add their definitions here


//==============================================================================
// class PlusOp
//==============================================================================


int PlusOp::operation(char op, int a, int b, int c)
{
    if(op != '+')
        throw std::logic_error("Operation  are not supported");

    // here we just ignore unused operands
    return a + b;
}

IOperation::Arity PlusOp::getArity() const
{
    return arDue;
}

//==============================================================================
// class StackMachine
//==============================================================================

// TODO: implement methods of the StackMachine class here

void StackMachine::registerOperation(char symb, IOperation * oper)
{
	SymbolToOperMapConstIter iter = _opers.find(symb);
	if (iter != _opers.end())
	{
		throw std::logic_error("Operation has already registered!");
	}
	_opers[symb] = oper;
}

IOperation * StackMachine::getOperation(char symb)
{
	return _opers[symb];
}

int StackMachine::calculate(const std::string & expr, bool clearStack)
{
	if (clearStack)
		_s.clear();

	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr[i] == ' ')
			continue;

		int sign = 0;
		if ((expr[i] == '+' || expr[i] == '-') && i + 1 < expr.length() && isdigit(expr[i + 1])) 
		{
			sign = expr[i] == '+' ? 1 : -1;
			++i;
		}
		else if (isdigit(expr[i]))
			sign = 1;

		if (sign != 0)
		{
			int number = 0;
			for (; i < expr.length() && expr[i] != ' '; ++i) 
			{
				if (isdigit(expr[i]))
					number = number * 10 + (expr[i] - '0');
				else
					throw std::logic_error("Invalid number");
			}
			--i;
			_s.push(sign * number);
		}
		else {
			IOperation* operation = getOperation(expr[i]);
			if (operation == nullptr)
				throw std::logic_error("Wrong operation");
			int a, b = 0, c = 0;
			if (operation->getArity() == IOperation::arUno)
				a = _s.pop();
			else if (operation->getArity() == IOperation::arDue)
			{
				b = _s.pop();
				a = _s.pop();
			}
			else 
			{
				c = _s.pop();
				b = _s.pop();
				a = _s.pop();
			}

			_s.push(operation->operation(expr[i], a, b, c));
		}
	}

	return _s.top();
}

int DivOp::operation(char op, int a, int b, int c)
{
	if (op != '/')
		throw std::logic_error("Operation  are not supported");

	return a / b;
}

IOperation::Arity DivOp::getArity() const
{
	return arDue;
}

int MulOp::operation(char op, int a, int b, int c)
{
	if (op != '*')
		throw std::logic_error("Operation  are not supported");

	return a * b;
}

IOperation::Arity MulOp::getArity() const
{
	return arDue;
}


int ChooseOp::operation(char op, int a, int b, int c)
{
	if (op != '?')
		throw std::logic_error("Operation  are not supported");
	if (a != 0)
	{
		return b;
	}
	else
	{
		return c;
	}
}

IOperation::Arity ChooseOp::getArity() const
{
	return arTre;
}

} // namespace xi
