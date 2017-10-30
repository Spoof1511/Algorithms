#ifndef _PARTS_CPP_
#define _PARTS_CPP_

#include <iostream>
#include "parts.h"

void Part::describe()
{
    std::map<const Part*,int>::iterator iter;
    std::cout<<"Part "<<this->name<<" subparts are:\n";
    for (iter=this->subparts.begin();iter!=this->subparts.end();iter++)
    {
       std::cout<<iter->second<<" "<<iter->first->name<<"\n";
    }
    if (this->subparts.size()==0)
        std::cout<<"It has no subparts\n";
}
int Part::countHowMany(const Part *p)
{
    if (p==this)
        return 1;
    int many=1;
    const Part* temp=p;
    for (;temp!=this;)
    {
        if(!temp)
            return 0;
       many=many*temp->father->subparts[p];
        temp=temp->father;
        p=p->father;
    }
    return  many;
}
void Part::addSon(Part *child, int quantity)
{
    this->subparts[child]=quantity;
    child->father=this;
}
void NameContainer::addPart(const std::string &part, int quantity, const std::string &subpart)
{
    Part* temp=lookup(part);
    Part* tempChild=lookup(subpart);
    temp->addSon(tempChild,quantity);

}
Part* NameContainer::lookup(const std::string &name)
{
    Part* temp=_nameMap[name];
    if (!temp)
    {
        temp = new Part(name);
        _nameMap[name] = temp;
    }
    return  temp;
}
#endif // _PARTS_CPP_





