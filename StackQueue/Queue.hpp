// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// queue

template <typename value_type>
Queue<value_type>::Queue(){
	used=0;	// starts at zero for empty constructor
}

template <typename value_type>
Queue<value_type>::Queue(Queue& source){
	data=source.data;
	used=1;	// starts at one if using data to initialize queue
}

template <typename value_type>
Queue<value_type>::~Queue(){
	data.~LinkedList<value_type>();	// call LinkedList destructor
}

template <typename value_type>
void Queue<value_type>::enqueue(const value_type& obj){
	++used;		// increment used
	data.addToTail(obj);	// add obj to queue, at the end of the queue
}

template <typename value_type>
const value_type Queue<value_type>::dequeue(){
	value_type temp = data.getHead();	// first assigns front data to a temp
	data.removeFromHead();				// removes the front data
	used--;
	return temp;						// returns front data
}

template <typename value_type>
const int Queue<value_type>::size(){
	data.start();	// set current to front of queue
	int count=0;	// temp int for holding the count
	if(data.currentCheck()){	// call current check method, that checks if current has data
		count++;				// increment count 
		data.forward();			// call forward method, to move current forward
	}else{return count;}
}

template <typename value_type>
value_type Queue<value_type>::front()const{
	return data.getHead();
}

template <typename value_type>
const double Queue<value_type>::average(){
	double total=0;						// temp double for holding sum of data
	Queue<value_type> queueTemp;		// make a temporary queue for holding the data
	int queueSize = used;				// temp int for holding original queue size, important not to change this
	for(int i = 0; i < queueSize; i++){	// loop will loop as many times as queue size
		total+=front();
		queueTemp.enqueue(front());		// assigns front value to the temporary queue
		dequeue();						// temp queue will be in reverse but this is fine
	}
	for(int i = 0; i < queueSize; i++){	// loops runs as many times as queue size again
		enqueue(queueTemp.dequeue());	// re-assign the values from the temp queue to the original queue again
	}return total/used;					// return the sum/queue length
}

template <typename value_type>
const int Queue<value_type>::minimum(){
	data.start();	// current=head
	int min=data.getCurrent();	// initiate first minimum, make equal to the first value in queue
	int check=0;
	for(data.start(); data.currentCheck(); data.forward()){
		check=data.getCurrent();
		if(min>check){	// if old minimum is lesser than current value
			min=check;	// min equals the new current value
		}
	}return min;
}

template <typename value_type>
const int Queue<value_type>::maximum(){
	data.start();	// similar to minimum
	int max=data.getCurrent();
	int check=0;
	for(data.start(); data.currentCheck(); data.forward()){
		check=data.getCurrent();
		if(max<check){
			max=check;
		}
	}return max;
}

template <typename value_type>
const double Queue<value_type>::stdeviation(){
	data.start();
	double total=0, std = 0, temp=0;
	for(data.start(); data.currentCheck(); data.forward()){
		total+=data.getCurrent();	// get the sum of queue
	}
	double avg=total/used;
	for(data.start(); data.currentCheck(); data.forward()){
		temp=data.getCurrent();
		std+=pow(temp - avg, 2);	// little bit of math for standard dev.
	}return sqrt(std/used);			// little bit more math; return std/length of queue
}
/*
template <typename value_type>
ostream& operator << (ostream& out, Queue<value_type>& target){
	cout << target.data;
}*/