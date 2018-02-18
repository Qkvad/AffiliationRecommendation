#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <list>
#include <algorithm>

#include "User.h"

class User;

class Group
{
public:
    Group(int _id, std::string nm);
    ~Group();

    void addMember(User* p);
    void addRandomMembers(std::list<User>* Users);
    void printMembers();

    /*****************************/

    int id;
    std::string name;
    int popularity;

    std::list<User*> members;
};

#endif