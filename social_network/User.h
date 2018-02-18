#ifndef USER_H
#define USER_H

#include <iostream>
#include <list>
#include <set>
#include <algorithm>

#include "Group.h"

class Group;

class User
{
public:
    User(int _id, std::string nm);
    ~User();

    void addFriend(User* p);
    void addRandomFriends(std::list<User>* Users);
    void printFriends();

    void addGroup(Group* g);
    void printGroups();

    /*****************************/

    int id;
    std::string name;
    int popularity;

    std::list<User*> friends;
    std::list<Group*> groups;
};

#endif