#include "Group.h"

#include "config.h"

Group::Group(int _id, std::string nm)
{
    id = _id;
    name = nm;
    popularity = 1 + std::rand() % MAX_GROUP_POPULARITY ;

    // create super popular user (1% of all users)
    int k = std::rand() % 100;
    if(k==1)
        popularity = MAX_GROUP_POPULARITY * (2 + std::rand() % 5);
}

Group::~Group()
{
}

void Group::addMember(Person* p)
{
    if(std::find(this->members.begin(), this->members.end(), p) == this->members.end())
    {
        this->members.push_front(p);
        //p->addGroup(this);
    }
}

void Group::addRandomMembers(std::list<Person>* persons)
{
    std::list<Person>::iterator iter = persons->begin();
    int k;

    for(int i=0; i<this->popularity; i++)
    {
        iter = persons->begin();
        k = std::rand() % NUMBER_OF_USERS;
        std::advance(iter, k);

        this->addMember(&(*iter));
    }

    //std::cout << "added random members to " << this->id << std::endl;
}

void Group::printMembers()
{
    std::cout << "Members of group " << this->name << "_" << this->id << ": " << this->members.size() << "  (popularity: " << this->popularity << ")" << std::endl;
    for(std::list<Person*>::iterator it = members.begin(); it != members.end(); it++)
        std::cout << (*it)->name << "_" << (*it)->id << std::endl;
    std::cout << std::endl;
}
