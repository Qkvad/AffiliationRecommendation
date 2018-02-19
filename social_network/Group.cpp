#include "Group.h"

#include "config.h"

Group::Group(int _id, std::string nm)
{
    id = _id;
    name = nm;
    popularity = 1 + std::rand() % MAX_GROUP_POPULARITY ;

	// forcebly create super popular group
	if(id <= FORCED_SUPER_POPULAR_GROUPS)
		popularity = popularity = MAX_GROUP_POPULARITY * (2 + std::rand() % 5);

    // randomly create super popular group (1% of all group)
    int k = std::rand() % 100;
    if(k==1)
        popularity = MAX_GROUP_POPULARITY * (2 + std::rand() % 5);
}

Group::~Group()
{
}

void Group::addMember(User* p)
{
    if(std::find(this->members.begin(), this->members.end(), p) == this->members.end())
    {
        this->members.push_front(p);
        p->addGroup(this);
    }
}

void Group::addRandomMembers(std::list<User>* Users)
{
    std::list<User>::iterator iter = Users->begin();
    int k;

    for(int i=0; i<this->popularity; i++)
    {
        iter = Users->begin();
        k = std::rand() % NUMBER_OF_USERS;
        std::advance(iter, k);

        this->addMember(&(*iter));
    }
}

void Group::printMembers()
{
    std::cout << "Members of group " << this->name << "_" << this->id << ": " << this->members.size() << "  (popularity: " << this->popularity << ")" << std::endl;
    for(std::list<User*>::iterator it = members.begin(); it != members.end(); it++)
        std::cout << (*it)->name << "_" << (*it)->id << std::endl;
    std::cout << std::endl;
}
