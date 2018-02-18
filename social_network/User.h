#ifndef User_H
#define User_H

#include <iostream>
#include <list>
#include <set>
#include <algorithm>

//#include "Group.h"

class User
{
public:
    User(int _id, std::string nm);
    ~User();

    void addFriend(User* p);
    void addRandomFriends(std::list<User>* Users);
    void printFriends();

    //void addGroup(Group* g);

    /*****************************/

    int id;
    std::string name;
    int popularity;

    std::list<User*> friends;
    //std::list<Group*> groups;
};

#endif