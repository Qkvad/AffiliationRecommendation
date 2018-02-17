#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <stack>
#include <unistd.h>

#include "Person.h"

typedef std::pair<int,int> friend_pair;

class Crawler
{
public:
    Crawler();

    void startCrawlWith(Person* p);
    void crawlEntireStack();
    void printFinding();

    std::stack<Person*> crawlStack;
    std::list<Person*> doneCrawling;
    std::list<friend_pair> foundFriendPairs;
};

#endif