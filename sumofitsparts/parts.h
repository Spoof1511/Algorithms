// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

// using namespace std;

//**************** Part ****************
class Part  {
public:
	Part* father;
	std::string name;
    std::map<const Part*,int > subparts;
	// TODO: Finish declaration
	
	Part(const std::string& n) : name(n) {};
	void describe();
	int countHowMany(const Part* p);
	void addSon(Part* child,int quantity);
};


//**************** NameContainer ****************
class NameContainer  {
public:        
	NameContainer() {};
    
    void addPart(const std::string& part, int quantity, const std::string& subpart);
	Part* lookup(const std::string& name);
        
    // You can add some methods here 
        
private:
	std::map<std::string, Part*> _nameMap;

};

#endif // _PARTS_H_
