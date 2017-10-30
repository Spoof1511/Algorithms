﻿////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


#include "safearray.h"


// we have to indicate that methods of the class Safearray are also inside the namespace xi
namespace xi {
	template<class T>
	inline SafeArray<T>::SafeArray(const SafeArray & arr)
	{
		_capacity = arr._capacity;
		_storage = new T[arr._capacity];
		for (int i = 0; i < arr._capacity; i++)
		{
			_storage[i] = arr._storage[i];
		}
	}
	template<class T>
	inline SafeArray<T> & SafeArray<T>::operator=(const SafeArray & arr)
	{
		_capacity = arr._capacity;
		delete[]_storage;
		_storage = new T[arr._capacity];
		for (int i = 0; i < arr._capacity; i++)
		{
			_storage[i] = arr._storage[i];
		}
		return *this;
	}
	template <class T>
SafeArray<T>::SafeArray(size_t cap)
{
	if (cap == 0)
	{
		_storage = nullptr;
		return;
	}
	_capacity = cap;
	_storage = new T[cap];
}

template<class T>
inline SafeArray<T>::~SafeArray()
{
	if (_storage != nullptr)
	{
		delete[]_storage;
	}
}

template<class T>
inline T & SafeArray<T>::operator[](size_t k)
{
	checkBounds(k);
	return _storage[k];
}

template<class T>
inline const T & SafeArray<T>::operator[](size_t k) const
{
	checkBounds(k);
	return _storage[k];
}

template<class T>
inline size_t SafeArray<T>::getCapacity() const
{
	return _capacity;
}

template<class T>
inline void SafeArray<T>::checkBounds(size_t index) const
{
	if (index >= _capacity) throw std::out_of_range("Index out of range!");
}

// TODO: здесь должно быть еще несколько методов


} // namespace xi
