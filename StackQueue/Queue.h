// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// queue

#ifndef QUEUE
#define QUEUE

#include "LinkedList.h"

template <typename value_type>
class Queue{
	public:
		// constructors
		// Pre: none
		// Post: creates an empty Queue
		Queue();
		// Pre: receives data
		// Post: creates Queue with that data
		Queue(Queue& source);
		
		// destructor
		// Pre: none
		// Post: calls LinkedList destructor
		~Queue();
		
		/********* member functions *********/
		// mutators
		// Pre: queue exists, receives data
		// Post: adds data to the end of the queue
		void enqueue(const value_type& obj);
		// Pre: data in queue
		// Post: removes data from front of the queue
		const value_type dequeue();
		
		// queries
		// Pre: queue exists
		// Post: returns int used (length of queue)
		const int size();
		// Pre: queue exists
		// Post: returns the data at the front of the queue
		value_type front()const;
		// Pre: queue exists
		// Post: returns average of the data in queue
		const double average();
		// Pre: queue exists
		// Post: returns the minimum data of the queue
		const int minimum();
		// Pre: queue exists
		// Post: returns the maximum data of the queue
		const int maximum();
		// Pre: queue exists
		// Post: returns the standard deviation of the queue
		const double stdeviation();
	private:
		LinkedList<value_type> data;	// data for queue	
		int used;	// int for holding the queue length, increments when adding, decrements when removing
};
/*
template <typename value_type>
ostream& operator <<(ostream&, Queue<value_type>&);
*/
#include "Queue.hpp"
#endif