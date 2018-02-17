#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <list>
#include <set>
#include <algorithm>

//#include "Group.h"

class Person
{
public:
    Person(int _id, std::string nm);
    ~Person();

    void addFriend(Person* p);
    void addRandomFriends(std::list<Person>* persons);
    void printFriends();

    //void addGroup(Group* g);

    /*****************************/

    int id;
    std::string name;
    int popularity;

    std::list<Person*> friends;
    //std::list<Group*> groups;
};

#endif