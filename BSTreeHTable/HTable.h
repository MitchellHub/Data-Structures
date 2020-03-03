// c3183623 MITCHELL HEDGES
// This defines a class that represents a
// Hash Table

#ifndef HASHTABLE
#define HASHTABLE

#include <sstream>

using namespace std;

template <typename item>
class HTable{
	public:
		// Constructors
		HTable();	// empty constructor
		// Destructor
		~HTable();
		
		// Mutators
		// PRE: takes an int
		// POST: adds the element to the array, with it's special 'hash' code
		void add(const int);
		
		// PRE: takes an int, that already exists inside the array
		// POST: removes the element matching the int from the array
		void remove(const int);
		
		// Queries
		// PRE: takes an int
		// POST: returns an integer between 1 and 150
		int hashFunction(const int);
		
		// PRE: an array exists, containing elements
		// POST: returns a string of all the elements in the array
		string hashString()const;
	private:
		int *array[150];	// private variable holding the data
};

template <typename item>
ostream& operator << (ostream& out, const HTable<item>& ht);	// overload for hastable

#include "HTable.hpp"
#endif