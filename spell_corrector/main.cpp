#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string stripPunct(const string& s);
void checkSpelling(ifstream& in, Dictionary& dict);
void insert_corrector(const string& word,Dictionary& dictionary);
void swap_corrector(const string& word,Dictionary& dictionary);
void remove_corrector(const string& word,Dictionary& dictionary);
void replace_corrector(const string& word,Dictionary& dictionary);


int main(int argc, char* argv[]) 
{
	// Output usage message if improper command line args were given.
	if (argc != 3)
    {
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) 
    {
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}

	// Read dictionary, but let user know what we are working on.
	cout << "Loading dictionary, this may take awhile...\n";

	Dictionary d(argv[1]);

	checkSpelling(inf, d);

	inf.close();

	return EXIT_SUCCESS;
}

void checkSpelling(ifstream& in, Dictionary& dict) 
{
	int line_number = 0;

	while (in) 
    {
		++line_number;

		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) 
        {
            word=stripPunct(word);
            lower(word);
            if(dict.search(word))
                continue;
            cout << "line " << line_number << ": '" << word << "' " << endl;
            cout << "\t" << "suggestions: " << endl;
            insert_corrector(word,dict);
            swap_corrector(word,dict);
            remove_corrector(word,dict);
            replace_corrector(word,dict);
		}
	}
}

void insert_corrector(const string& word,Dictionary& dictionary)
{
    string str;
    for (int i='a';i<='z';i++)
    {
        str=word;
        str+=i;
        if (dictionary.search(str))
        {
            std::cout<<"\t\t"<<str<<endl;
        }
    }
}
void swap_corrector(const string& word,Dictionary& dictionary)
{
    char temp;
    string str;
    for (int i=0;i<word.size()-1;i++)
    {
        str=word;
        temp=word[i];
        str[i]=str[i+1];
        str[i+1]=temp;
        if(dictionary.search(str))
            cout<<"\t\t"<<str<<endl;
    }
}
void replace_corrector(const string& word,Dictionary& dictionary)
{
    string str;
    string part;
    for (int i=0;i<word.size();i++)
    {
        for (int j='a';j<='z';j++)
        {
            str=word;
            str[i]=j;
            if (dictionary.search(str))
                cout<<"\t\t"<<str<<endl;
            if(word[i]==j)
                continue;
            part=word.substr(i,word.length()-i);
            str=word.substr(0,i)+(char)j+part;
            if (dictionary.search(str))
                cout<<"\t\t"<<str<<endl;
        }
    }
}
void remove_corrector(const string& word,Dictionary& dictionary)
{
    string str;
    for (int i=0;i<word.size();i++)
    {
        str=word;
        if (word[i]!=word[i+1])
            str.erase(i,1);
        if(dictionary.search(str))
            cout<<"\t\t"<<str<<endl;
    }
}
void lower(string& s) 
{
    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); ++i) 
    {
		s[i] = tolower(s[i]);
	}
}

string stripPunct(const string& s) 
{
	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1])) 
		return s.substr (0, s.length() - 1);
	
    return s;
}
