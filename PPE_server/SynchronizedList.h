#ifndef SYNCHRONIZEDLIST_INCLUDED
#define SYNCHRONIZEDLIST_INCLUDED
#include <iostream>
#include <list>

//thread
#include <pthread.h>


class SynchronizedList
{
	public:
		SynchronizedList();
		~SynchronizedList();

		void addElement(std::string str);

		std::string getFirstElement();

		bool isEmpty();

	private:
		std::list<std::string> queue;
		pthread_mutex_t mutex;
};

#endif // SYNCHRONIZEDLIST_INCLUDED
