// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// linked list

template <typename value_type>
LinkedList<value_type>::LinkedList(){	// create new empty list (without data)
	head = NULL;
	tail = NULL;
	list_length = 0;
}

template <typename value_type>
LinkedList<value_type>::LinkedList(const value_type& data){	// create new list with data
	head = new Node<value_type>(data);
	tail = head;							// list is only one node long, therefore head = tail
	list_length = 1;
}

template <typename value_type>
LinkedList<value_type>::~LinkedList(){	// destruct list
	/* //old overcomplicated destructor method
	start();	// set current = head
	Node<value_type>* tempNode = current;	// tempNode for holding node to be deleted
	while(current != NULL){
		tempNode = current;
		current = current->get_next();	// important to hold the node for deleting, and then moving 
		delete tempNode;				// current to next before deleting the node
	}*/
	// new, simple, amazing destructor method
	while(head!=NULL){
		removeFromHead();	// call removeFromHead to do the destructing - genius!!
	}
}
// addcurrent is not finished do not use
template <typename value_type>
void LinkedList<value_type>::addCurrent(const value_type& data){
	Node<value_type>* add_ptr = new Node<value_type>(data);		// creates new node on heap
	add_ptr->set_next(current->get_next());		// sets new node's next ptr to current's next ptr
	current->set_next(add_ptr);					// sets current's next ptr to new node
	if (current == tail){tail = current->get_next();}	// if current was the tail, tail = current's next ptr
	current = current->get_next();	// set current to it's next ptr.
}

template <typename value_type>
void LinkedList<value_type>::addToTail(const value_type& data){
	if(list_length == 0){	// empty list case
		head = new Node<value_type>(data);
		current = head;
		tail = head;
		list_length=1;
	}else{
		Node<value_type>* temp_node = new Node<value_type>(data);	// creates new Node on heap
		tail->set_next(temp_node);	// sets this node to the new tail
		temp_node->set_prev(tail);	// sets old tail to second last node
		tail = temp_node;	// sets old tail to new tail
		list_length++; 		// increment list length
		temp_node = NULL; 	// resets temp node
	}
}

template <typename value_type>
void LinkedList<value_type>::addToHead(const value_type& data){
	if(list_length == 0){	// empty list case
		head = new Node<value_type>(data);
		current = head;
		tail = head;
		list_length=1;
	}else{
		Node<value_type>* temp_node = new Node<value_type>(data);	// creates new Node on heap
		head->set_prev(temp_node);	// sets this node to the new head
		temp_node->set_next(head);	// sets old head to second node
		head = temp_node;	// sets old head to new head
		list_length++; 		// increment list length
		temp_node = NULL; 	// resets temp node
	}
}

template <typename value_type>
void LinkedList<value_type>::removeCurrent(){
	if(list_length==0){return;}					// case for empty list
	if (current != head and current != tail){	// case only works for a middle node
		Node<value_type>* temp_node = current;				// holding current is important to delete it later after the links are moved
		Node<value_type>* next_node = current->get_next();	// get next node to later re-link with current
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

template <typename value_type>
void LinkedList<value_type>::removeFromHead(){
	if(list_length==0){return;}
	else if(list_length==1){
		delete head;
		head = NULL;
		tail = NULL;
		list_length--;
		return;
	}else{
		Node<value_type>* temp_node = head;
		head = temp_node->get_next();
		delete temp_node;
		list_length--;
		temp_node = NULL;
	}
}

template <typename value_type>
void LinkedList<value_type>::remove(const std::string deletThis){
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

template <typename value_type>
void LinkedList<value_type>::start(){
	current = head;
}

template <typename value_type>
void LinkedList<value_type>::end(){
	current = tail;
}

template <typename value_type>
void LinkedList<value_type>::forward(){
	current = current->get_next();
}

template <typename value_type>
void LinkedList<value_type>::back(){
	current = current->get_prev();
}

template <typename value_type>
value_type LinkedList<value_type>::getCurrent()const{
	return current->get_data();
}

template <typename value_type>
value_type LinkedList<value_type>::getTail()const{
	return tail->get_data();
}

template <typename value_type>
value_type LinkedList<value_type>::getHead()const{
	if(head != NULL){
		return head->get_data();
	}return 0;
}

template <typename value_type>
void LinkedList<value_type>::printList(){
	for (current = head; current != NULL; current = current->get_next()){
		cout << current->get_data();
	}
}

template <typename value_type>
double LinkedList<value_type>::calcAverage(){
	double t;
	value_type dataTemp;
	start();
	while (current != NULL){
		dataTemp=current->get_data();
		t += dataTemp.get_score();
		forward();
	}return t/list_length;	// scores divided by list length
}

template <typename value_type>
int LinkedList<value_type>::count(const std::string countThis){
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

template <typename value_type>
bool LinkedList<value_type>::currentCheck(){
	if(current!=NULL){
		return true;
	}else{return false;}
}

template <typename value_type>
void LinkedList<value_type>::operator += (LinkedList& list2){
	list2.start();
	while (list2.currentCheck()){
		addToTail(list2.getCurrent());
		list2.forward();
	}return;
}

template <typename value_type>
ostream& operator << (ostream& out, LinkedList<value_type>& target){
	target.start();
	for (target.start(); target.currentCheck(); target.forward()){
		out << target.getCurrent();		// as node is already overloaded
	}return out;
}