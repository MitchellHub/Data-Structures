// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// Binary Tree Node

template <typename value_type>
BTNode<value_type>::BTNode(){		// empty constructor
	data = NULL;
	left = NULL;
	right = NULL;
	parent = NULL;
}

template <typename value_type>
BTNode<value_type>::BTNode(const value_type& initial_data, BTNode* left_node, BTNode* right_node, BTNode* parent_node){
	data = initial_data;		// instantiate a BTNode with data, and optionally with left, right and parent node
	left = left_node;
	right = right_node;
	parent = parent_node;
}

template <typename value_type>
BTNode<value_type>::~BTNode(){
	// delete data;	// this doesn't work
	set_left(NULL);	// destruct node, making all ptrs = NULL. 
	set_right(NULL);
	set_parent(NULL);
}

template <typename value_type>
void BTNode<value_type>::set_data(const value_type& new_data){
	data=new_data;
}

template <typename value_type>
void BTNode<value_type>::set_parent(BTNode* parent_ptr){
	parent=parent_ptr;
}

template <typename value_type>
void BTNode<value_type>::set_left(BTNode* left_ptr){
	left=left_ptr;
}

template <typename value_type>
void BTNode<value_type>::set_right(BTNode* right_ptr){
	right=right_ptr;
}

template <typename value_type>
value_type BTNode<value_type>::get_data() const{
	return data;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_parent() const{
	return parent;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_right() const{
	return right;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_left() const{
	return left;
}

template <typename value_type>
ostream& operator <<(ostream& out, const BTNode<value_type>* target) {
    out << target->get_data();
    return out;
}