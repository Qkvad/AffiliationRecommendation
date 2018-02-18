#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <stack>
#include <unistd.h>

#include "User.h"

typedef std::pair<int,int> friend_pair;

class Crawler
{
public:
    Crawler();

    void startCrawlWith(User* p);
    void crawlEntireStack();
    void printFinding();

    std::stack<User*> crawlStack;
    std::list<User*> doneCrawling;
    std::list<friend_pair> foundFriendPairs;
};

#endif