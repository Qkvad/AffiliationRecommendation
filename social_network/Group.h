#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <list>
#include <algorithm>

#include "Person.h"

class Group
{
public:
    Group(int _id, std::string nm);
    ~Group();

    void addMember(Person* p);
    void addRandomMembers(std::list<Person>* persons);
    void printMembers();

    /*****************************/

    int id;
    std::string name;
    int popularity;

    std::list<Person*> members;
};

#endif