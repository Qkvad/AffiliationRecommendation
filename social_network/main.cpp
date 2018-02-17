#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>

#include "config.h"

#include "Person.h"
#include "Group.h"
#include "Crawler.h"

void createUsers(std::list<Person>* persons)
{
    for(int i=0; i<NUMBER_OF_USERS; i++)
        persons->push_back(Person(i+1, "person"));

    std::cout << "Persons list created."<< std::endl;
}

void createGroups(std::list<Group>* groups)
{
    for(int i=0; i<NUMBER_OF_GROUPS; i++)
        groups->push_back(Group(i+1, "group"));

    std::cout << "Group list created."<< std::endl;
}

Person* chooseRandomPerson(std::list<Person>* persons)
{
    std::list<Person>::iterator iter = persons->begin();
    int k = std::rand() % NUMBER_OF_USERS;

    std::advance(iter, k);

    return &(*iter);
}

int main()
{
    std::list<Person> allUsers;
    std::list<Group> allGroups;

    std::list<Person>::iterator u_it;
    std::list<Group>::iterator g_it;

    createUsers(&allUsers);
    createGroups(&allGroups);

    //std::list<Person>::iterator it = allUsers.end();
    //(--it)->popularity = 20;
    //(--it)->popularity = 1;

    srand (time(NULL));

    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++) {
        u_it->addRandomFriends(&allUsers);
        u_it->printFriends();
        //sleep(1);
    }

	std::cout << "Users friended."<< std::endl;

    int uSize = allUsers.size();
    int nonZero = 0;
    std::ofstream matrixS;
    matrixS.open ("S.mtx");
    matrixS << "%%MatrixMarket matrix coordinate real general\n";
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<Person*>::iterator f_it = u_it->friends.begin(); f_it != u_it->friends.end(); f_it++)
            nonZero++;
    matrixS << uSize << " " << uSize << " "<< nonZero << std::endl;
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<Person*>::iterator f_it = u_it->friends.begin(); f_it != u_it->friends.end(); f_it++)
            matrixS << u_it->id << " " << (*f_it)->id << " 1\n";
    matrixS.close();

	std::cout << "users by users matrix S created."<< std::endl;


    for(g_it = allGroups.begin(); g_it != allGroups.end(); g_it++) {
        g_it->addRandomMembers(&allUsers);
        g_it->printMembers();
        //sleep(1);
    }

	std::cout << "Groups filled."<< std::endl;

    int gSize = allGroups.size();
    nonZero = 0;
    std::ofstream matrixA;
    matrixA.open ("A.mtx");
    matrixA << "%%MatrixMarket matrix coordinate real general\n";
    for(g_it = allGroups.begin(); g_it != allGroups.end(); g_it++)
        for (std::list<Person*>::iterator m_it = g_it->members.begin(); m_it != g_it->members.end(); m_it++)
            nonZero++;
    matrixA << gSize << " " << uSize << " "<< nonZero << std::endl;
    for(g_it = allGroups.begin(); g_it != allGroups.end(); g_it++)
        for (std::list<Person*>::iterator m_it = g_it->members.begin(); m_it != g_it->members.end(); m_it++)
            matrixA << g_it->id << " " << (*m_it)->id << " 1\n";
    matrixA.close();

	std::cout << "groups by users matrix A created."<< std::endl;


    /*
    Crawler crawl;
    crawl.startCrawlWith(chooseRandomPerson(&allUsers));
    crawl.crawlEntireStack();
    crawl.printFinding();
    */

    return 0;
}
