#include "User.h"
#include "config.h"

User::User(int _id, std::string nm)
{
    id = _id;
    name = nm;
    popularity = 1 + std::rand() % MAX_USER_POPULARITY ;

    // create super popular user (1% of all users)
    int k = std::rand() % 100;
    if(k==1)
        popularity = MAX_USER_POPULARITY * (2 + std::rand() % 5);
}

User::~User()
{
}

void User::addFriend(User* p) {
    if (p->id == this->id) return;
    if (std::find(this->friends.begin(), this->friends.end(), p) == this->friends.end()) {
        this->friends.push_front(p);
        p->addFriend(this);
    }

    // join to group in which this friend latest joined (in 25% of times)
    if (rand() % 100 < 25)
        if (p->groups.begin() != p->groups.end())
            this->addGroup(*(p->groups.begin()));
}

void User::addRandomFriends(std::list<User>* Users)
{
    std::list<User>::iterator iter = Users->begin();
    int k;

    for(int i=0; i<this->popularity; i++)
    {
        iter = Users->begin();
        k = std::rand() % NUMBER_OF_USERS;
        std::advance(iter, k);

        this->addFriend(&(*iter));
    }

    //std::cout << "added random friends to " << this->id << std::endl;
}

void User::printFriends()
{
    std::cout << "Friends of " << this->name << "_" << this->id << ": " << this->friends.size() << "  (popularity: " << this->popularity << ")" << std::endl;
    for(std::list<User*>::iterator it = friends.begin(); it != friends.end(); it++)
        std::cout << (*it)->name << "_" << (*it)->id << std::endl;
}

void User::addGroup(Group *g)
{
    if(std::find(this->groups.begin(), this->groups.end(), g) == this->groups.end())
        groups.push_front(g);
}

void User::printGroups()
{
    std::cout << "Groups of " << this->name << "_" << this->id << ": " << this->groups.size() << std::endl;
    for(std::list<Group*>::iterator it = groups.begin(); it != groups.end(); it++)
        std::cout << (*it)->name << "_" << (*it)->id << std::endl;
}
