// c3183623 MITCHELL HEDGES
// This implements a class that represents a node

template <typename value_type>
Node<value_type>::Node(const value_type& initial_data, Node* init_link, Node* prev_link){
	data = initial_data;
	next = init_link;
	previous = prev_link;
}

template <typename value_type>
Node<value_type>::~Node(){
	previous = NULL;
	next = NULL;
}

template <typename value_type>
void Node<value_type>::set_data(const value_type& new_data){
	data=new_data;
}

template <typename value_type>
void Node<value_type>::set_next(Node* next_ptr){
	next = next_ptr;
}

template <typename value_type>
void Node<value_type>::set_prev(Node* prev_ptr){
	previous = prev_ptr;
}

template <typename value_type>
value_type Node<value_type>::get_data ()const{
	return data;
}

template <typename value_type>
Node<value_type>* Node<value_type>::get_next() const{
	return next;
}

template <typename value_type>
Node<value_type>* Node<value_type>::get_prev() const{
	return previous;
}

template <typename value_type>
ostream& operator <<(ostream& out, const Node<value_type>* target)
{
    out << target->get_data();
    return out;
}