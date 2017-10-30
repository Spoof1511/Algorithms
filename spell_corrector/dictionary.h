#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>

#include  "hashset.h"
#include  "hashset.cpp"

//using namespace std;

class hash_function {
public:
    hash_function() {}
    /*rot13*/
    unsigned int operator()(const std::string& s) const
    {
        unsigned int hash = 0;
        const char* str=s.c_str();
        for(; *str; str++)
        {
            hash += (unsigned char)(*str);
            hash -= (hash << 13) | (hash >> 19);
        }

        return hash;
    }
};

class equality {
public:
    equality() {}
    bool  operator()(const std::string& a, const std::string& b)  const 
    {
		return  (a == b);
    }
};


class Dictionary: public HashSet<std::string, hash_function, equality>
{
public:
   Dictionary(std::string s):HashSet<std::string,hash_function,equality>()
   {
       string word;
       ifstream word_file(s);
       if (!word_file)
           throw std::invalid_argument("Couldnt open file!");

       if(word_file.is_open())
       {
           while (getline(word_file,word))
           {
               insert(word);
           }
           word_file.close();
       }
   }
};

#endif
