// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// stack

template <typename value_type>
Stack<value_type>::Stack(){
	stackLength=0;	// stack length zero when no data
}

template <typename value_type>
Stack<value_type>::Stack(Stack& source){
	stackLength=1;	// stack length starts at one when constructing with data
	data=source.data;
}

template <typename value_type>
Stack<value_type>::~Stack(){
	data.~LinkedList<value_type>();	// calls LinkedList destructor
}

template <typename value_type>
void Stack<value_type>::push(const value_type& obj){
	stackLength++;
	data.addToHead(obj);	// adds data at top of stack
}

template <typename value_type>
const value_type Stack<value_type>::pop(){
	value_type temp = data.getHead();	// first assigns top data to a temp
	data.removeFromHead();				// removes the top data
	stackLength--;
	return temp;						// finally, return that data
}

template <typename value_type>
int Stack<value_type>::size()const{
	return stackLength;
}

template <typename value_type>
value_type Stack<value_type>::top()const{
	return data.getHead();
}

template <typename value_type>	// overload for ostream operator
ostream& operator << (ostream& out, Stack<value_type>& target){
	Stack<value_type> stackTemp;	// make a temporary stack for holding the data
	out << "( ";
	int stackSize = target.size();	// temp int for holding original stack size, important not to change this
	for(int i = 0; i < stackSize; i++){	// loop will loop as many times as stack size
		stackTemp.push(target.top());	// assigns (push) top value to the temporary stack
		out << target.pop() << " ";		// pop the top value from original stack, and print it
	}									// temporary stack is in reverse order but this is good
	for(int i = 0; i < stackSize; i++){	// loops runs as many times as stack size again
		target.push(stackTemp.pop());	// re-assign (push) the values from the temp stack to the orignal stack again
	}									// original stack will now be in correct order
	out << ")";
	return out;
}