////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Main module for xi Point project
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      14.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// The module provides only a simple "smoke" test if the point class compiles well.
///
////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include "xipoint.h"



int main(int argc, char** argv)
{
    using namespace xi;

	std::cout<<"Hello, world!";
	Point p(1, 1);
	Point p1(2, 2);
	Point p2(3, 3);
	Point p3(4, 4);
	Point p4(5, 5);
	Point p5(7, 7);
	Point kek[] = { p,p1,p2,p3,p4 };
	PointArray ar1(kek, 5);
	PointArray ar2(ar1);
    
	ar2.append(p);
	Point* kekos = ar2.get(2);

	ar2.insert(p5, 0);
	ar2.remove(1);

	system("pause");

}
