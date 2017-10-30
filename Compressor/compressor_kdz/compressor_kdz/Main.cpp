//КДЗ-1 по дисциплине Алгоритмы и структуры данных
//Исаков Алан Эсенович, БПИ 154 , 5.12.2016
//Visual studio 2015, Compressor.h , Compressor.cpp , Main.cpp
#include "Compressor.h"
#include <iostream>
#include <map>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;


void Hcompress(std::string input);
void Scompress(std::string input);
void Hdecompress(std::string input);
void Sdecompress(std::string input);
//void timer_kek(void(*func)(string), string input);

//typedef long long ll;
//std::ofstream streamkek("res.csv");
Compressor compressor;

//Example for run from the command line with parameters: C:\Users\Alan\Desktop\compressor_kdz\x64\Release\compressor_kdz "h" "c" D:\test
// 1-arg path to the exe , 2-method Huffman or Shannon-Fano ("h" или "s"), 3-Comress or Decompress ("c" or "d"),4-path to the file
int main(int argc, char* argv[])
{
	if (argc <= 2) {
		std::cout << "Not enough arguments!" << std::endl;
		return 0;

	}
	else if (argc > 4) {
		std::cout << "So much arguments!" << std::endl;
		return 1;
	}
	if ((std::string)argv[1] == "h") {
		if ((std::string)argv[2] == "c") {
			Hcompress((std::string)argv[3]);
		}
		else if ((std::string)argv[2] == "d") {
			Hdecompress((std::string)argv[3]);
		}
	}
	else if ((std::string)argv[1]=="s")
	{
		if ((std::string)argv[2] == "c") {
			Scompress((std::string)argv[3]);
		}
		else if ((std::string)argv[2] == "d")
		{
			Sdecompress((std::string)argv[3]);
		}
	}
	
	/*std::string* names = new std::string[24]{ "0_20480","0_40960","0_61440","0_81920","0_102400","0_1048576","0_2097152","0_3145728",
	"1_20480","1_40960","1_61440","1_81920","1_102400","1_1048576","1_2097152","1_3145728",
		"2_20480","2_40960","2_61440","2_81920","2_102400","2_1048576","2_2097152","2_3145728" };
	for (int i = 0; i < 24; i++) {
		timer_kek(Scompress,names[i]);
	}
	streamkek.close();
	system("pause");*/
}

void Hcompress(std::string input) {
		compressor.go_compress(input, "h");
}
void Scompress(std::string input) {
		compressor.go_compress(input, "s");

}
void Hdecompress(std::string input) {
		compressor.go_decompress(input, "h");
}
void Sdecompress(std::string input) {
		compressor.go_decompress(input, "s");
}

//void timer_kek(void (*func)(string),string input) {
//	ll sum = 0;
//	ll current;
//	ll maxim = 0;
//	for (int t = 0; t < 10; t++) {
//		auto first = chrono::high_resolution_clock::now();
//		func(input);
//		auto second = chrono::high_resolution_clock::now();
//	current = chrono::duration_cast<chrono::nanoseconds> (second - first).count();
//	sum += current;
//	}
//	ll average = sum / (ll)10.0;
//	const char *cstr = input.c_str();
//	streamkek << cstr << ";" << average << endl;
//}