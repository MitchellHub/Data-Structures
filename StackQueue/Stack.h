// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// stack

#ifndef STACK
#define STACK

#include "LinkedList.h"

template <typename value_type>
class Stack{
	public:
		// constructors
		// Pre: none
		// Post: creates an empty Stack
		Stack();
		// Pre: recievse data
		// Post: creates stack with data, size 1
		Stack(Stack& source);
		// destructor
		// Pre: stack exists
		// Post: calls LinkedList destructor
		~Stack();
		
		/********* member functions *********/
		// mutators
		// Pre: Stack exists, recieves data
		// Post: adds data to top of Stack
		void push(const value_type& obj);
		// Pre: Stack exists with data
		// Post: returns data from top of stack, and returns it
		const value_type pop();
		
		// queries
		// Pre: Stack exists
		// Post: returns stackLength
		int size()const;
		// Pre: Stack exists with data
		// Post: returns top data of stack
		value_type top()const;
		
	private:
		LinkedList<value_type> data;	// data for the stack
		int stackLength;				// length of the stack, increments when adding, decrements when removing
};
template <typename value_type>
ostream& operator <<(ostream&, Stack<value_type>&);
#include "Stack.hpp"
#endif