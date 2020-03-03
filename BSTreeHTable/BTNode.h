// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// Binary Tree Node

#ifndef BTNODE
#define BTNODE

#include <iostream>
#include <math.h>

using namespace std;

template <typename value_type>
class BTNode{
	public:
		// Constructors
		BTNode();
		BTNode(const value_type& initial_data=value_type(), BTNode* left_node=NULL, BTNode* right_node=NULL, BTNode* parent_node=NULL);
		// Destructor
		~BTNode();
		
		// Mutators
		// PRE: node exists, takes some data
		// POST: sets data of node to this data
		void set_data(const value_type& new_data);
		
		// PRE: node exists, takes a node
		// POST: sets parent pointer to this node
		void set_parent(BTNode*);
		
		// PRE: node exists, takes a node
		// POST: sets left child pointer to this node
		void set_left(BTNode*);
		
		// PRE: node exists, takes a node
		// POST: sets the right child pointer to that node
		void set_right(BTNode*);
		
		// Queries
		// PRE: node exists
		// POST: returns data held by node
		value_type get_data() const;
		
		// PRE: node exists
		// POST: returns pointer to parent node
		BTNode* get_parent() const; 
		
		// PRE: node exists
		// POST: returns pointer to right child node
		BTNode* get_right() const;
		
		// PRE: node exists
		// POST: returns pointer to left child node
		BTNode* get_left() const;
	private:
		value_type data;		// private variable holding any data of <value_type>
		BTNode* left;			// pointer for left child node
		BTNode* right;			// ptr for right child node
		BTNode* parent;			// ptr for parent node
};

template <typename value_type>
ostream& operator <<(ostream&, const BTNode<value_type>*);	// overload for printing nodes

#include "BTNode.hpp"
#endif