// c3183623 MITCHELL HEDGES
// This implements a class that represents a
// Hash Table

template <typename item>
HTable<item>::HTable()
{
	for(int i = 0; i < 150; i++){
		array[i] = NULL;		// populates an array with NULL values
	}
}

template <typename item>
HTable<item>::~HTable()
{
	for(int i = 0; i < 150; i++){
		delete array[i];		// loops through the array to delete every item
	}
}

template <typename item>
void HTable<item>::add(const int data)
{
	array[hashFunction(data)] = new item(data);	// place data in a certain position in the array, using the hashfunction
}

template <typename item>
void HTable<item>::remove(const int data)
{
	delete array[hashFunction(data)];		// delete an array entry in a certain position (given by the hashfunction)
	array[hashFunction(data)] = NULL;		// then set it to NULL
}

template <typename item>
int HTable<item>::hashFunction(const int value)
{
	return value%150;		// the 'formula' for the hashtable, returns the remainder of value divided by 150.
}

template <typename item>
string HTable<item>::hashString()const
{
	stringstream str;					// string for cout overload
		for(int i = 0; i < 150; i++){
			if(array[i] != NULL){			// skip NULL values in array
				str << *array[i] << " ";	// add value to string
			}
		}			
	return str.str();						// return string
}

template <typename value_type>
ostream& operator << (ostream& os, const HTable<value_type>& ht)
{
	return os << ht.hashString();
}