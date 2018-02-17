#include "Person.h"
#include "config.h"

Person::Person(int _id, std::string nm)
{
    id = _id;
    name = nm;
    popularity = 1 + std::rand() % MAX_USER_POPULARITY ;

    // create super popular user (1% of all users)
    int k = std::rand() % 100;
    if(k==1)
        popularity = MAX_USER_POPULARITY * (2 + std::rand() % 5);
}

Person::~Person()
{
}

void Person::addFriend(Person* p)
{
    if(std::find(this->friends.begin(), this->friends.end(), p) == this->friends.end())
    {
        this->friends.push_front(p);
        p->addFriend(this);
    }
}

void Person::addRandomFriends(std::list<Person>* persons)
{
    std::list<Person>::iterator iter = persons->begin();
    int k;

    for(int i=0; i<this->popularity; i++)
    {
        iter = persons->begin();
        k = std::rand() % NUMBER_OF_USERS;
        std::advance(iter, k);

        this->addFriend(&(*iter));
    }

    std::cout << "added random friends to " << this->id << std::endl;
}

void Person::printFriends()
{
    std::cout << "Friends of user " << this->name << "_" << this->id << ": " << this->friends.size() << "  (popularity: " << this->popularity << ")" << std::endl;
    for(std::list<Person*>::iterator it = friends.begin(); it != friends.end(); it++)
        std::cout << (*it)->name << "_" << (*it)->id << std::endl;
    std::cout << std::endl;
}

/*void Person::addGroup(Group *g)
{
    groups.push_front(g);
}*/