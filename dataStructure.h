/* This is the header file for data structures of CS 300 class.
 * It covers (will cover) classes of 
 *   - array list
 *   - linked list
 *   - stack
 *   - queue
 *   - binary search tree
 *   - hash table
 * 
 * Author: Huabo Lu 
 *
 * Last modified: 09/18/2016
 */ 



// we will define the capacity of array to be 100
// note that there is no semicolon followed by 100 
#define ARRAY_CAPACITY 100


// define class ArrayList
class ArrayList
{
public:
 	
	// type can be easily changed here, and just here. 
	typedef int value_type;

	// default constructor 
	ArrayList(){count = 0;}
	
	// we don't need copy constructor or custom constructor so far
	
	// addElement() function will add an element at the end. 
	//   return true if success. 
	//   return false if Array List is full.
	bool addElement(value_type newElement);
	
	// deleteElement() function will delete the element given by index. 
	//   return true if deleted.
	//   return false if incorrect index
	bool deleteElement(int index);
	
	// getElement() function will get element on index.
	//   pre-condition: index must be in proper range. 
	//   return the element to caller. 
	value_type getElement(int index);
	
	// setElement() function will set element on index. 
	//   pre-conditionL index must be in proper range. 
	void setElement(int index, value_type newElement);
	
	// getCount() function will return count to caller. 
	int getCount();
	
	
private:
	// two variables will be created here:
	//  1. one array to store elements, with preset capacity
	//  2. one integer to count how many elements in array. 
 	value_type array[ARRAY_CAPACITY];
 	int count;

};