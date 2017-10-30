////////////////////////////////////////////////////////////////////////////////
// Module Name:  xipoint.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         14.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "xipoint.h"

#include <algorithm>  // min

namespace xi {

	// TODO: put the method implementations here

	Point::Point(int x, int y)
	{
		_x = x;
		_y = y;
	}

	void Point::shift(int shf)
	{
		_x += shf;
		_y += shf;
	}

	void Point::shift(int xSh, int ySh)
	{
		_x += xSh;
		_y += ySh;
	}

	void Point::shift(const Point & pt)
	{
		_x += pt.getX();
		_y += pt.getY();
	}

	int Point::getX() const
	{
		return _x;
	}

	int Point::getY() const
	{
		return _y;
	}

	void Point::setX(int x)
	{
		_x = x;
	}

	void Point::setY(int y)
	{
		_y = y;
	}

	PointArray::PointArray()
	{
		_arr = new Point[0];
		_size = 0;
	}

	PointArray::PointArray(const Point points[], const Uint n)
	{
		_size = n;
		_arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			_arr[i] = points[i];
		}
	}

	PointArray::PointArray(const PointArray & pv)
	{
		_size = pv.getSize();
		_arr = new Point[_size];

		for (int i = 0; i < _size; i++)
		{
			_arr[i] = pv.getRawPtr()[i];
		}
	}

	PointArray::~PointArray()
	{
		delete[]_arr;
	}

	void PointArray::append(const Point & pt)
	{
		int newSize = _size + 1;
		resize(newSize);
		_arr[newSize - 1] = pt;
	}

	void PointArray::insert(const Point & pt, Uint pos)
	{
		if (pos >= _size)
		{
			append(pt);
		}
		else
		{
			int newSize = _size + 1;
			resize(newSize);
			for (int i = newSize - 1; i > pos; i--)
			{
				_arr[i] = _arr[i-1];
			}
			_arr[pos] = pt;
		}

	}

	void PointArray::remove(const Uint pos)
	{
	    if(pos<_size&&(_size!=1&&pos!=0))
		{
			for (int i = pos; i < _size; i++) 
			{
				_arr[i] = _arr[i + 1];
			}
			resize(_size - 1);
		}
		else 
		{
			clear();
		}
		
	}

	void PointArray::clear()
	{
		resize(0);
		_arr = nullptr;
	}

	const PointArray::Uint PointArray::getSize() const
	{
		return _size;
	}

	Point * PointArray::get(Uint pos)
	{
		if (pos > _size)
		{
			return nullptr;
		}

		return _arr +pos;
	}

	const Point * PointArray::get(Uint pos) const
	{
		if (pos > _size)
		{
			return nullptr;
		}

		Point* temp = _arr;
		return temp += pos;
	}

	void PointArray::resize(Uint n)
	{
		Point* temp = new Point[n];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = _arr[i];
		}

		delete[]_arr;
		_arr = temp;
		_size = n;
		
	}


} // namespace xi {