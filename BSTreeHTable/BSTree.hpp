// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// Binary Search Tree

template <typename item>		// this one definitely works though :~]
BSTree<item>::BSTree()
{
	root=NULL;
	treeSize=0;
}
/*		
template <typename item>		// ****************************************   unused constructor
BSTree<item>::BSTree(BTNode<item>* root_node){
	root=root_node;
	treeSize=1;
}

template <typename item>		// ***************************************  unused constructor 
BSTree<item>::BSTree(const item data, BSTree* left_sub, BSTree* right_sub){
	root = new BTNode<item>();
	root->set_data(data);
	
	if(left_sub != NULL){
		root->set_left(left_sub->get_root());
		left_sub->get_root()->set_parent(root);
	}
	else {root->set_left(NULL);}
	
	if (right_sub != NULL){
		root->set_right(right_sub->get_root());
		right_sub->get_root()->set_parent(root);
	}
	else{root->set_right(NULL);}
}*/

template <typename item>
BSTree<item>::~BSTree()
{
	destructTree(root);
}

template <typename item>
void BSTree<item>::destructTree(BTNode<item>* node)
{
	if(node == NULL){return;}
	destructTree(node->get_right());	// recursive call for right sub tree
	destructTree(node->get_left());		// recursive call for left sub tree
	
	delete node;
}

template <typename item>			// recursive method for insertion ;)
void BSTree<item>::add(const item it)
{
	if(root == NULL) {root = new BTNode<item>(it);}	
	else			 {insert(root, it);}	// calls helper method starting at root
	treeSize++;
}

template <typename item>			// helper method for insertion
void BSTree<item>::insert(BTNode<item>* node, const item it)
{
	if (it == node->get_data()){
		node->set_data(it);						// if node is the same, replace existing item (no duplicates)
	}
	else if (it > node->get_data()){			// right side (item is bigger)
		if(node->get_right() == NULL){
			node->set_right(new BTNode<item>(it));	// if right child empty, set data
			node->get_right()->set_parent(node);	// link to parent
		}
		else{insert(node->get_right(), it);}	// recursive call for right child node, restart process
	}
	else{										// left side (item is smaller)
		if(node->get_left() == NULL){
			node->set_left(new BTNode<item>(it));	// if left child empty, set data
			node->get_left()->set_parent(node);		// link to parent
		}
		else{insert(node->get_left(), it);}		// recursive call for left child node, restart process
	}
}

template <typename item>			// recursive method for remove
void BSTree<item>::remove(const item delet)
{
	BTNode<item>* node = find(root, delet);	// create a node and then call find which returns a node and assigns it to 'node'
	remove(node);							// recursive call for remove taking a BTNode<item>
}

template <typename item>			// helper method for remove
void BSTree<item>::remove(BTNode<item>* node)
{	// i'll have you know this took me a very long time
	if(node == NULL){
		return;				// if value isn't found, return.
	}

	if(node->get_left() == NULL && node->get_right() == NULL){			// no children case
		if(node->get_parent()->get_left() == node){		// checks which side node is on
			node->get_parent()->set_left(NULL);			// NULLs the pointer from parent to node
		}
		else{node->get_parent()->set_right(NULL);}
		delete node;
		treeSize--;
		return;
	}
	if (node->get_left() != NULL && node->get_right() == NULL){ 		// case for one left child
		node->set_data(node->get_left()->get_data());	// sets data for target node to left child
		remove(node->get_left());						// then calls remove for the left child
	}		
	else if (node->get_left() == NULL && node->get_right() != NULL){	// case for one right child
		node->set_data(node->get_right()->get_data());	// sets data for target node to right child
		remove(node->get_right());		// etc
	}
	else{																// case for two children
		BTNode<item>* tempNode = node->get_left();	// starts temp node at left child
		while(tempNode->get_right() != NULL){		// basically, finds the largest value to the right of the left child of target...
			tempNode=tempNode->get_right();			// trust me it works.
		}
		node->set_data(tempNode->get_data());		// finally, retrieves this value and sets the original node to that value
		remove(tempNode);	// recursive call to delete this last node, which should delete node via 'no children case'
	}
	return;	// whew
}

template <typename item>
BTNode<item>* BSTree<item>::find(BTNode<item>* node, const item findThis)
{
	if (node == NULL){return NULL;}		// returns NULL if 'find' reaches a NULL node
	else{
		if (findThis == node->get_data()){			// if data found, return the corresponding node
			return node;
		}
		else if(findThis > node->get_data()){		// if greater, start find on right child node
			return find (node->get_right(), findThis);
		}											// else start find on left child
		else {return find(node->get_left(), findThis);
		}
	}
}

template <typename item>
BTNode<item>* BSTree<item>::get_root() const
{
	return root;
}

template <typename item>		// recursive method for infix
std::string BSTree<item>::infix()
{
	return infix(get_root());
}

template <typename item>		// helper method
string BSTree<item>::infix(BTNode<item>* node)
{
	stringstream str;	// using stringstream as cannot for the life of me get 
						// "return infix(left) + node + infix(right)" to work...
						// get a 'no match for operator+ string and int' error...
						// stringstream str() seems to work though
						// hopefully this causes no problems with marking
	if(node == NULL){
		return "";
	}
	else{
		// return infix(node->get_left()) + node->get_data() + infix(node->get_right());
		// ^ doesn't work
		str << infix(node->get_left()) << " " << node->get_data() << infix(node->get_right());
		return str.str();	// i hope this works on the uni computers lol
	}
}

template <typename item>
ostream& operator << (ostream& out, BSTree<item>& tree)
{
	return out << tree.infix();		// calls infix 
}