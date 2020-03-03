//TreeHashTableDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of binary seach trees and hash tables. 

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BTNode.h"
#include "BSTree.h"
#include "HTable.h"

using namespace std;

int main()
{
clock_t t;

	// if you are using class templates
	BSTree<int> treeValues;
	HTable<int> tableValues;

	int vectorMarks[] = {123454, 23418, 787626, 56534, 879840, 5465443, 5650, 678760, 3456462, 34465, 97567, 345169, 1456769, 867570, 565471};
	int numberOfElements = (int)sizeof(vectorMarks)/(int)sizeof(vectorMarks[0]);
	
	cout << "==================" << endl << "BINARY SEARCH TREE" << endl;
	t = clock(); // gets current time
	for (int i=0; i<numberOfElements; i++) {treeValues.add(vectorMarks[i]);} // populates the tree.
    
	cout << "Initial tree: " << treeValues << endl; // prints the contents of the tree.
	
	
    for (int i=0; i<1; i++)
    { // add and remove over and over again
        treeValues.remove(123454); treeValues.remove(787626); treeValues.remove(678760); treeValues.remove(22670); treeValues.remove(56534); treeValues.remove(1456769); treeValues.remove(5465443);
	    treeValues.add(123454);treeValues.add(787626);treeValues.add(678760); treeValues.add(56534);treeValues.add(1456769);treeValues.add(5465443);
	}
	cout << "Final tree  : " << treeValues << endl << endl; // prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(100000*14) << " milliseconds." << endl << endl;
	

	cout << "==================" << endl << "HASH TABLE" << endl;
	t = clock(); // gets current time
    for (int i=0; i<numberOfElements; i++) {tableValues.add(vectorMarks[i]);} // populates the hash table.
    cout << "Initial hash table: " << tableValues << endl; // prints the contents of the hash table.

	for (int i=0; i<100000; i++)
	{ // add and remove over and over again
	 	tableValues.remove(123454); tableValues.remove(787626); tableValues.remove(678760); tableValues.remove(22670); tableValues.remove(56534); tableValues.remove(1456769); tableValues.remove(5465443);
	    tableValues.add(123454);tableValues.add(787626);tableValues.add(678760); tableValues.add(56534);tableValues.add(1456769);tableValues.add(5465443);
	}
	cout << "Final hash table  : " << tableValues << endl << endl; // prints the contents of the hash table.
    cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(100000*14) << " milliseconds." << endl << endl;

	cout << "The program has finished." << endl;
	return 0;
}