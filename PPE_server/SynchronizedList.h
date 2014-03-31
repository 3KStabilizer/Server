#ifndef SYNCHRONIZEDLIST_INCLUDED
#define SYNCHRONIZEDLIST_INCLUDED
#include <iostream>
#include <list>

//thread
#include <pthread.h>


/**
 * @brief provide a list with mutex machinism to allow mutual access from different thread
 *
 */
class SynchronizedList
{
	public:
        /**
         * @brief main constructor
         */
		SynchronizedList();
        /**
         * @brief main destructor
         *
         */
        ~SynchronizedList();

        /**
         * @brief add securely an element to the list
         *
         * @param str the element to add
         */
        void addElement(std::string str);

        /**
         * @brief get and remove securely the first element of the list
         *
         * @return std::string the first element
         */
        std::string getFirstElement();

        /**
         * @brief check if the current list is empty
         *
         * @return bool true if empty false otherwise
         */
        bool isEmpty();

	private:
        std::list<std::string> queue; /**< the queue itself */
        pthread_mutex_t mutex; /**< the mutex to prevent from concurrent modification */
};

#endif // SYNCHRONIZEDLIST_INCLUDED
