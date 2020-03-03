// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// linked list

#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList(){	// create new empty list (without data)
	head = NULL;
	tail = NULL;
	list_length = 0;
}

LinkedList::LinkedList(const value_type& data){	// create new list with data
	head = new Node(data);
	tail = head;							// list is only one node long, therefore head = tail
	list_length = 1;
}

LinkedList::~LinkedList(){	// destruct list
	start();	// set current = head
	Node* tempNode = current;	// tempNode for holding node to be deleted
	while(current != NULL){
		tempNode = current;
		current = current->get_next();	// important to hold the node for deleting, and then moving 
		delete tempNode;				// current to next before deleting the node
	}
}

void LinkedList::addCurrent(const value_type& data){
	Node* add_ptr = new Node(data);
	add_ptr->set_next(current->get_next());
	current->set_next(add_ptr);
	if (current == tail){tail = current->get_next();}
	current = current->get_next();
}

void LinkedList::addToTail(const value_type& data){
	if(list_length == 0){	// empty list case
		head = new Node(data);
		current = head;
		tail = head;
		list_length=1;
	}else{
		Node* temp_node = new Node(data);	// creates new Node on heap
		tail->set_next(temp_node);	// sets this node to the new tail
		temp_node->set_prev(tail);	// sets old tail to second last node
		tail = temp_node;	// sets old tail to new tail
		list_length++; 		// increment list length
		temp_node = NULL; 	// resets temp node
	}
}

void LinkedList::removeCurrent(){
	if(list_length==0){return;}					// case for empty list
	if (current != head and current != tail){	// case only works for a middle node
		Node* temp_node = current;				// holding current is important to delete it later after the links are moved
		Node* next_node = current->get_next();	// get next node to later re-link with current
		current = temp_node->get_prev();		// move current back one, so it is the previous of the node to be deleted
		current->set_next(next_node);			// link current with the 'next' node
		next_node->set_prev(current);			// link the 'next' node with current
		delete temp_node;						// finally delete the node
		list_length--;
		return;
	}else if (current == head){					// case for head 
		current = current->get_next();
		delete head;
		head = current;
		list_length--;
		return;
	}else if (current == tail){					// case for tail
		current = current->get_prev();
		delete tail;
		tail = current;
		list_length--;
	}
}

void LinkedList::remove(const std::string deletThis){
	start();
	value_type dataCheck;
	std::string strCheck;
	
	while(current != NULL){
		dataCheck = current->get_data();
		strCheck = dataCheck.get_name();
		if (strCheck==deletThis){
			removeCurrent();
		}forward();
	}
}
/* old code
std::string LinkedList::listToString()const{
	Node* tempNode;
	std::string listString;
	for (tempNode = head; tempNode != NULL; tempNode = tempNode->get_next()){
		listString += tempNode->get_string();
	} return listString;
}*/

void LinkedList::start(){
	current = head;
}

void LinkedList::end(){
	current = tail;
}

void LinkedList::forward(){
	current = current->get_next();
}

void LinkedList::back(){
	current = current->get_prev();
}
LinkedList::value_type LinkedList::getCurrent()const{
	return current->get_data();
}

LinkedList::value_type LinkedList::getTail()const{
	return tail->get_data();
}

LinkedList::value_type LinkedList::getHead()const{
	return head->get_data();
}

void LinkedList::printList(){		
	// this method be remade like the += operator overload, but I'm not sure if it would be better. 
	// See the overload for more details
	for (current = head; current != NULL; current = current->get_next()){
		cout << current->get_data();
	}
}

double LinkedList::calcAverage(){
	// this method be remade like the += operator overload, but I'm not sure if it would be better. 
	// See the overload for more details
	double t;
	value_type dataTemp;
	start();
	while (current != NULL){
		dataTemp=current->get_data();
		t += dataTemp.get_score();
		forward();
	}return t/list_length;	// scores divided by list length
}
/* old method used for testing, this shouldn't be used at all due to returning private variable
int LinkedList::size()const{
	return list_length;
}*/

int LinkedList::count(const std::string countThis){
	// this method be remade like the += operator overload, but I'm not sure if it would be better. 
	// See the overload for more details
	start();
	int t=0;
	value_type dataCheck;
	std::string strCheck;
	while(current != NULL){
		dataCheck = current->get_data();
		strCheck = dataCheck.get_name();
		if (strCheck==countThis){
			t++;
		}forward();
	}return t;
}

bool LinkedList::currentCheck(){
	if(current!=NULL){
		return true;
	}else{return false;}
}
/* old code for overloading
void LinkedList::operator += (LinkedList& list2){
	Node* tempNode;
	value_type tempData;
	tempNode=list2.head;
	while (tempNode != NULL){
		tempData=tempNode->get_data();
		addToTail(tempData);
		tempNode = tempNode->get_next();
	}return;
}*/
/* re-made += operator 2.0
void LinkedList::operator += (LinkedList& list2){
	list2.start();
	value_type tempData;
	while (list2.currentCheck()){
		tempData=list2.getCurrent();
		addToTail(tempData);
		list2.forward();
	}return;
}*/

void LinkedList::operator += (LinkedList& list2){
	// re-made += operator 3.0, this method doesn't use any temp variables and makes use of currentCheck/getCurrent
	// not sure if this is a better way of doing things. Most of my methods could be remade this way.
	list2.start();
	while (list2.currentCheck()){
		addToTail(list2.getCurrent());
		list2.forward();
	}return;
}

/* old code for doing the ostream a weird way
ostream& operator << (ostream& out, const LinkedList& target){
	out << target.listToString();
	return out;
}*/

ostream& operator << (ostream& out, LinkedList& target){
	target.start();
	for (target.start(); target.currentCheck(); target.forward()){
		out << target.getCurrent();		// as node is already overloaded
	}return out;
}