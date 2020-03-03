// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// Binary Search Tree

#ifndef BSTREE
#define BSTREE

#include <iostream>
#include <sstream>		// for infix()
#include "BTNode.h"

using namespace std;

template <typename item>

class BSTree{
	public:
		// **** Constructors **** 
		BSTree(); // Empty constructor
		
		// **** Destructors **** 
		~BSTree();
		// PRE: takes a node, probably the root node
		// POST: destructs all sub trees below the node, and recursively calls itself
		void destructTree(BTNode<item>* node);
		
		// **** Mutators **** 
		
		// PRE: takes an item 
		// POST: if root is null, make new node using this item. Otherwise call insert
		void add(const item);
		
		// PRE: takes a NODE and an ITEM (node will normally be the root of a tree, and then recursive)
		// POST: inserts into the tree, in the correct position
		void insert(BTNode<item>*, const item);
		
		// PRE: takes an item to search for
		// POST: calls FIND to return a node, then calls REMOVE using this node
		void remove(const item);
		
		// PRE: takes a NODE
		// POST: removes this NODE, re-balancing the tree in the process. Tricky stuff
		void remove(BTNode<item>* node);
		
		// **** Queries ****
		// PRE: takes a NODE (at first the root, and then recursive) and an item to search for
		// POST: returns the NODE matching the ITEM
		BTNode<item>* find(BTNode<item>* node, const item);
		
		// PRE: tree exists
		// POST: returns root of tree
		BTNode<item>* get_root() const;
		
		// PRE: tree exists
		// POST: returns infix(root)
		string infix();
		
		// PRE: takes a node, normally the root node of a tree
		// POST: returns a string of the tree, ascending from lowest value
		string infix(BTNode<item>* node);
	private:
		BTNode<item>* root;	// the tree's root node, i.e the first node in the tree
		int treeSize;		// int for keeping tree size, isn't actually used though :)
};
template <typename item>
ostream& operator << (ostream& out, BSTree<item>& tree);	// overload for tree, simply calls the infix method

#include "BSTree.hpp"
#endif