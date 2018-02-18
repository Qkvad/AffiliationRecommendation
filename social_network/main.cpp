#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>

#include "config.h"

#include "User.h"
#include "Group.h"
#include "Crawler.h"

void createUsers(std::list<User>* Users)
{
    for(int i=0; i<NUMBER_OF_USERS; i++)
        Users->push_back(User(i+1, "User"));

    std::cout << "Users list created."<< std::endl;
}

void createGroups(std::list<Group>* groups)
{
    for(int i=0; i<NUMBER_OF_GROUPS; i++)
        groups->push_back(Group(i+1, "group"));

    std::cout << "Group list created."<< std::endl;
}

User* chooseRandomUser(std::list<User>* Users)
{
    std::list<User>::iterator iter = Users->begin();
    int k = std::rand() % NUMBER_OF_USERS;

    std::advance(iter, k);

    return &(*iter);
}

int main()
{
    std::list<User> allUsers;
    std::list<Group> allGroups;

    std::list<User>::iterator u_it;
    std::list<Group>::iterator g_it;

    createUsers(&allUsers);
    createGroups(&allGroups);

    srand (time(NULL));

    for(g_it = allGroups.begin(); g_it != allGroups.end(); g_it++)
        g_it->addRandomMembers(&allUsers);

    std::cout << std::endl << "Groups filled." << std::endl << std::endl;

    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        u_it->addRandomFriends(&allUsers);

	std::cout << "Users friended."<< std::endl << std::endl;

    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++) {
        u_it->printFriends();
        u_it->printGroups();
        std::cout << std::endl;
    }

    for(g_it = allGroups.begin(); g_it != allGroups.end(); g_it++) {
        g_it->printMembers();
    }

    /******************************************************************************************************************/

    int uSize = allUsers.size();
    int nonZero = 0;
    std::ofstream matrixS;
    matrixS.open ("S.mtx");
    matrixS << "%%MatrixMarket matrix coordinate real general\n";
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<User*>::iterator f_it = u_it->friends.begin(); f_it != u_it->friends.end(); f_it++)
            nonZero++;
    matrixS << uSize << " " << uSize << " "<< nonZero << std::endl;
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<User*>::iterator f_it = u_it->friends.begin(); f_it != u_it->friends.end(); f_it++)
            matrixS << u_it->id << " " << (*f_it)->id << " 1\n";
    matrixS.close();

	std::cout << "users by users matrix S created."<< std::endl << std::endl;

    int gSize = allGroups.size();
    nonZero = 0;
    std::ofstream matrixA;
    matrixA.open ("A.mtx");
    matrixA << "%%MatrixMarket matrix coordinate real general\n";
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<Group*>::iterator g_it = u_it->groups.begin(); g_it != u_it->groups.end(); g_it++)
            nonZero++;
    matrixA << uSize << " " << gSize << " "<< nonZero << std::endl;
    for(u_it = allUsers.begin(); u_it != allUsers.end(); u_it++)
        for (std::list<Group*>::iterator g_it = u_it->groups.begin(); g_it != u_it->groups.end(); g_it++)
            matrixA << u_it->id << " " << (*g_it)->id << " 1\n";
    matrixA.close();

	std::cout << "users by groups matrix A created."<< std::endl;


    /*
    Crawler crawl;
    crawl.startCrawlWith(chooseRandomUser(&allUsers));
    crawl.crawlEntireStack();
    crawl.printFinding();
    */

    return 0;
}
