#include "NiceQueue.h"

template<class T>
inline NiceQueue<T>::NiceQueue(size_t capacity):inStack(capacity),outStack(capacity)
{

	m_capacity = capacity;
}

template<class T>
inline size_t NiceQueue<T>::size(void) const
{
	return inStack.size() + outStack.size();
}

template<class T>
inline void NiceQueue<T>::enq(T newelement) throw(out_of_range)
{
	if (size() >= m_capacity) throw std::out_of_range("Queue is full!");
	inStack.push(newelement);
}

template<class T>
inline T NiceQueue<T>::deq(void) throw(out_of_range)
{
	if (size() == 0) throw std::out_of_range("Queue is empty!");
	if (outStack.size() == 0)
	{
		while(inStack.size() != 0)
		{
			T temp = inStack.pop();
			outStack.push(temp);
		}
	}
	T end = outStack.pop();
	return end;
}

template<class T>
inline T NiceQueue<T>::getMinimum(void) throw(out_of_range)
{
	if (outStack.size() == 0 && inStack.size() == 0) throw std::out_of_range("Queue is empty!");
	T minimum;
	((outStack.size() != 0) && (inStack.size() != 0)) ? (outStack.getMinimum() < inStack.getMinimum() ? minimum = outStack.getMinimum() : minimum = inStack.getMinimum()) : false;
	((outStack.size() != 0) && (inStack.size() == 0)) ? minimum = outStack.getMinimum() : minimum = inStack.getMinimum();
	return minimum;
}
