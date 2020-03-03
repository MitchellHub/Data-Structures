// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// linked list

#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include "Student.h"

using namespace std;

class LinkedList{
	public:
		/********* typedef *********/
		typedef Node::value_type value_type; // value_type Node, which contains a value_type specified in Node
		
		/********* constructors *********/
		// Pre: None
		// Post: Creates empty linked list
		LinkedList();
		// Pre: Receives data
		// Post: Creates linked list with data
		LinkedList(const value_type& data);
		
		/********* destructor *********/
		~LinkedList();
		
		
		/*********  member functions *********/
		
		/********* mutators *********/
		// Pre: recieves data
		// Post: creates a new double linked node at the tail of linked list
		void addCurrent(const value_type& data);
		// Pre: recieves data
		// Post: creates a new double linked node at the position of 'current'
		void addToTail(const value_type& data);
	
		// Pre: linked list exists, current points to a value_type
		// Post: removes current and links prev and next nodes to eachother again
		void removeCurrent();
		
		// Pre: takes input a of string
		// Post: removes node with name that matches string, and double links prev and next nodes to eachother again
		void remove(const std::string deletThis);
		
		// std::string listToString()const; old code
		
		// methods for moving(setting) 'current' Node*. Pre: None
		void start();	// Post: sets current to the head
		void end();		// Post: sets current to the tail
		void forward();	// Post: sets current one node to the right
		void back();	// Post: sets current one node to the left
		
		/********* getters/queries *********/
		// Pre: LinkedList exists
		// Post: returns 'current' data of linked list
		value_type getCurrent()const;
		// Pre: LinkedList exists
		// Post: returns tail data of linked list
		value_type getTail()const;
		// Pre: LinkedList exists
		// Post: returns head data of linked list 
		value_type getHead()const;
		
		// Pre: LinkedList exists
		// Post: Returns score divided by list_length only relevant to student, perhaps should be changed
		double calcAverage();
		
		// Pre: LinkedList exists
		// Post: Prints all data from linkedList starting at head
		void printList();
		
		// int size()const; unused method that is bad bad
		
		// Pre: LinkedList exists, recieves a string
		// Post: searches list for string, increments an int whenever the string is found. returns int
		int count(const std::string countThis);
		// Pre: LinkedList exists
		// Post: returns false if current is NULL, useful for checking if current is NULL without actually 
		// accessing current's data etc
		bool currentCheck();
		
		// overloaded += operator for concatenating lists
		// operator mutates data, so needs to be inside linkedlist class.
		// Pre: a linked list on left side, list2 input
		// Post: a linked list is concatenated with list2
		void operator += (LinkedList& list2);	
		
	 private:
		/********* variables *********/
		Node* head;			// Node pointer pointing to the last Node
		Node* tail;			// Node pointer pointing to the last Node
		Node* current;		// Node pointer pointing to 'current' node, can be moved around with methods. 
							// Useful for creating node in specific position or looping through a list
							
		int list_length;	// int for keeping track of list length
};

// overloaded ostream operator for printing linked list
// std::ostream& operator << (std::ostream& out, LinkedList& target);

ostream& operator <<(ostream&, LinkedList&);

#endif