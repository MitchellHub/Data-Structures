// c3183623 MITCHELL HEDGES
// This implements a class that represents a node

#include "Node.h"
#include <string>

using namespace std;


Node::Node(const value_type& initial_data, Node* init_link, Node* prev_link){
	data = initial_data;
	next = init_link;
	previous = prev_link;
}

Node::~Node(){
	previous = NULL;	// ?? these are pointless i think because they're automatically wiped. Not sure what else to put in here
	next = NULL;
	// delete data; // students made in main are not created using 'new'... so delete doesn't work? maybe? i don't know?
	// i'm pretty sure this constructor doesn't actually do anything, and probably shouldn't exist.
}

void Node::set_data(const value_type& new_data){
	data=new_data;
}

void Node::set_next(Node* next_ptr){
	next = next_ptr;
}

void Node::set_prev(Node* prev_ptr){
	previous = prev_ptr;
}

Node::value_type Node::get_data ()const{
	return data;
}
/* old code
std::string Node::get_string()const{
	std::string str;
	std::string name = data.get_name();
	std::string score = std::to_string(data.get_score());
	str = "(" + name + "," + score + ")   ";
	return str;
}*/

Node* Node::get_next() const{
	return next;
}

Node* Node::get_prev() const{
	return previous;
}

ostream& operator <<(ostream& out, const Node* target)
{
    out << target->get_data();	// value_type (student) needs to be overloaded for this to work
    return out;
}
