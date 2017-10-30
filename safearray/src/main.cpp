////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         30.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "safearray.h"
#include "subject.h"
#include <fstream>
#include<assert.h>


using namespace std;
const std::string filepath = "C:\\Users\\Alan\\Desktop\\prj\\res\\raw\\Subjects.txt";

int main()
{
    using namespace xi;

	Subject subject;
	std::filebuf fb;
	if (fb.open(filepath, std::ios::in))
	{
		std::istream is(&fb);

		for (int i = 0; i < 10; ++i) {
			is >> subject;
			std::cout << subject << std::endl;
		}

		fb.close();
	}



	SafeArray<std::string> arrayCopy1 = subject.description;
	SafeArray<std::string> arrayCopy2 = SafeArray<std::string>(subject.description);
	assert(arrayCopy1.getCapacity() == arrayCopy2.getCapacity());



	size_t capacity = arrayCopy1.getCapacity();
	if (capacity != 0) {
		std::string first1 = arrayCopy1[0];
		std::string first2 = arrayCopy2[0];
		assert(first1 == first2);

		arrayCopy1[0] = "";
		arrayCopy2[0] = "";

		first1 = arrayCopy1[0];
		first2 = arrayCopy2[0];
		assert(first1 == first2);
	}



	arrayCopy1 = SafeArray<std::string>(10);
	arrayCopy2 = SafeArray<std::string>(arrayCopy1);
	assert(arrayCopy1[9] == arrayCopy2[9]);



	SafeArray<int> arrayTest(0);
	assert(arrayTest.getRawPtr() == nullptr);



	arrayTest = SafeArray<int>(1);
	arrayTest[0] = 1;
	assert(arrayTest[0] == 1);



	bool error = false;
	try
	{
		arrayTest[1] = 1;
	}
	catch (std::out_of_range e)
	{
		error = true;
	}
	assert(error);



	Subject sub = Subject("CS", "Computer science");
	sub.description[0] = "SCSCSCS";
	std::cout << sub;



	SafeArray<int> sa;
	assert(sa.getRawPtr() == nullptr);
	assert(sa.getCapacity() == 0);



	SafeArray<int> sa1(3);
	assert(sa1.getRawPtr() != nullptr);
	assert(sa1.getCapacity() == 3);



	SafeArray<int> sa2(1);
	assert(sa2.getRawPtr() != nullptr);
	assert(sa2.getCapacity() == 1);
	sa2[0] = 0;
	assert(sa2[0] == 0);
	const int el0 = sa2[0];
	assert(el0 == sa2[0]);



	SafeArray<int> sa3(1);
	assert(sa3.getRawPtr() != nullptr);
	assert(sa3.getCapacity() == 1);
	SafeArray<int> sb = sa3;
	assert(sb.getRawPtr() != nullptr);
	assert(sb.getCapacity(), 1);
	assert(sa.getRawPtr() != sb.getRawPtr());

	return 0;
}