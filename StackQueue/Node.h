// c3183623 MITCHELL HEDGES
// This defines a class that represents a node

#ifndef NODE
#define NODE

#include <iostream>
//#include <cstdlib>
#include <math.h>
//#include "Student.h"

using namespace std;

template <typename value_type>
class Node{
	public:
		/********* typedef *********/
		// typedef Student value_type;
		
		/********* constructors *********/
		Node(const value_type& initial_data=value_type(), Node* init_link=NULL, Node* prev_link=NULL);
		
		/********* destructor *********/
		~Node();
		
		/*********  member functions *********/
		/********* mutators *********/
		// Pre: Node exists, receives data specified by typedef
		// Post: sets the data of a Node to this new data
		void set_data(const value_type& new_data);
		// Pre: Node exists, receives a Node*
		// Post: sets the next Node* to the Node* received
		void set_next(Node* next_ptr);
		// Pre: Node exists, receives a Node*
		// Post: sets the previous Node* to the Node* received
		void set_prev(Node* prev_ptr);
		
		/********* getters/queries *********/
		// Pre: Node exists
		// Post: returns the data inside the node
		value_type get_data() const;
		// Pre: Node exists
		// Post: returns Node* next
		Node* get_next() const;
		// Pre: Node exists
		// Post: returns the Node* previous
		Node* get_prev() const;
	private:
		/********* variables *********/
		value_type data;	// data of a typedef specified type
		Node* next;			// Node pointer pointing to next node in list
		Node* previous;		// Node pointer pointing to previous node in list
};
template <typename value_type>
ostream& operator <<(ostream&, const Node<value_type>*);
#include "Node.hpp"
#endif