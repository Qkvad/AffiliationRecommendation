#include "Crawler.h"


Crawler::Crawler()
{
    std::cout << "crawler init"<< std::endl;
}

void Crawler::startCrawlWith(User* p)
{
    for(std::list<User*>::iterator it = p->friends.begin(); it != p->friends.end(); it++)
    {
        foundFriendPairs.push_back(std::make_pair(p->id, (*it)->id));

        if(std::find(doneCrawling.begin(), doneCrawling.end(), *it) == doneCrawling.end())
            crawlStack.push(*it);
    }

    doneCrawling.push_front(p);

    this->printFinding();
}

void Crawler::crawlEntireStack()
{
    std::cout << "stack crawling";
    while(!crawlStack.empty())
    {
        User* st = crawlStack.top();
        startCrawlWith(st);
        crawlStack.pop();
        sleep(1);
    }
}

void Crawler::printFinding()
{
    std::cout << std::endl;
    for(std::list<friend_pair>::iterator it = foundFriendPairs.begin(); it != foundFriendPairs.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
}

