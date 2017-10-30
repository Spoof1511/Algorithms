#include "NiceStack.h"
#include <algorithm>

template<class T>
inline NiceStack<T>::NiceStack(size_t capacity)
{
	m_capacity = capacity;
}

template<class T>
inline size_t NiceStack<T>::size() const
{
	return storage.size();
}

template<class T>
inline NiceStack<T>::~NiceStack(void)
{

}

template<class T>
inline void NiceStack<T>::push(T newelement) throw(out_of_range)
{
	if (storage.size() >= m_capacity) throw std::out_of_range("Stack is full!");
	(storage.size() > 0) ?storage.push_back(make_pair(newelement,min(newelement,getMinimum()))) : storage.push_back(make_pair(newelement, newelement));
}

template<class T>
inline T NiceStack<T>::pop(void) throw(out_of_range)
{
	if (storage.size()== 0) throw std::out_of_range("Stack is empty!");
	T temp = storage.back().first;
	storage.pop_back();
	return temp;
}

template<class T>
inline T NiceStack<T>::getMinimum(void) throw(out_of_range)
{
	if (storage.size() == 0) throw std::out_of_range("Stack is empty!");
	return storage.back().second;
}
