#include "SynchronizedList.h"

SynchronizedList::SynchronizedList()
{
    //this->mutex = PTHREAD_MUTEX_INITIALIZER;
}
SynchronizedList::~SynchronizedList()
{

}

void SynchronizedList::addElement(std::string str)
{
    pthread_mutex_lock (&mutex);
    queue.push_back(str);
    pthread_mutex_unlock (&mutex);
}

std::string SynchronizedList::getFirstElement()
{
    if( queue.empty() )
        return "";
    pthread_mutex_lock (&mutex);
    std::string res = queue.front();
    queue.pop_front();
    pthread_mutex_unlock (&mutex);
    return res;
}

bool SynchronizedList::isEmpty()
{
    return queue.empty();
}

