/* This is the implementation file for data structures of CS 300 class.
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


#include "dataStructure.h"

#include <iostream>

using namespace std;


// pitfall: use ArrayList::value_type, not value_type

bool ArrayList::addElement(ArrayList::value_type newElement)
{
	if (count < ARRAY_CAPACITY)
	{
		array[count] = newElement;
		count++;
		return true;
	}
	else 
		return false;	

}

bool ArrayList::deleteElement(int index)
{
	if (index < count)
	{
		for (int i = index; i < count - 1; i ++)
		{
			array[i] = array[i + 1];
		}
		count--;
		return true;
	}
	else 
		return false;
}

// pre-condition for getElement(): index must be in range, i.e. less than count
ArrayList::value_type ArrayList::getElement(int index)
{
	return array[index];
}

// pre-condition for setElement(): index must be in range, i.e. less than count
void ArrayList::setElement(int index, ArrayList::value_type newElement)
{
	array[index] = newElement;
}

int ArrayList::getCount()
{
	return count;
}


int main()
{
	// create ArrayList object
	 ArrayList arrlist;
	
	// print out initial count, which should be 0.
	cout<<"Initial Count: "<<arrlist.getCount()<<endl;
	
	// test addElement() function
	for (int i = 0; i < 11; i ++)
		if(arrlist.addElement(i*i+1))
			cout<<"Adding "<<(i*i+1)<<" successfully"<<endl;
	cout<<"Initial Count: "<<arrlist.getCount()<<endl;

	// test deleteElement() function 
	if(arrlist.deleteElement(0))
		cout<<"Element at index 0 deleted"<<endl;
	cout<<"Initial Count: "<<arrlist.getCount()<<endl;
, which has a pre-condition
	for(int i = 0; i < arrlist.getC
	// test getElement() functionount(); i++)
		cout<<"ArrayList @ index: "<<i<<" : "<<arrlist.getElement(i)<<endl;
	
	// test setElement() function, which has a pre-condition
	arrlist.setElement(arrlist.getCount()-1, 99999);
	arrlist.setElement(0, -11111);
	for(int i = 0; i < arrlist.getCount(); i++)
		cout<<"ArrayList @ index: "<<i<<" : "<<arrlist.getElement(i)<<endl;
}



