/* streamExercise.cpp is an exercise on io stream and file stream.
 * 
 * Written by: Huabo Lu
 * 
 * Last update: Sep 12, 2016.
 */


#include <iostream>				// for std::cin and std::cout
#include <fstream>				// for file stream
#include <string>				// for string type
#include <limits>				// for numeric_limits<streamsize>::max()

// I am not going to use namespace std;
// see homework question why using namespace is a bad practice. 

// functions declaration
void basicCout();
void basicCoutHelper1(std::ostream&);
void basicCin();
void basicCinHelper1();
void basicCinHelper2();
void basicCinHelper3();
void basicCinHelper4();
void basicCinHelper5();
void fileIO();
void fileIOWrite();
void fileIORead();


int main()
{
	// basicCout();
	
	// basicCin();
	
	
	// fileIO ();
	
		
	return 0;
}


// basic practice of std::cout
void basicCout()
{
	std::cout<<"This is a std::cout, "
		<<"where cout is an object of class ostream. "
		<<"\n"
		<<"Operator \"<<\" is called formatted insertion operator. "
		<<std::endl;


	std::cout<<"\nSince cout is an object, you can pass it to a function"<<std::endl;
	basicCoutHelper1(std::cout);
	
	
	// since cout is an object, you can print its address. 
	std::cout<<"\nAddress of cout is: "<<&std::cout<<std::endl;
	
	// for more information go to a reference of std::cout 
	// http://www.cplusplus.com/reference/iostream/cout/
}

void basicCoutHelper1(std::ostream& someObject)
{
	someObject<<"Hello World! to some ostream object. "<<std::endl;

}

void basicCin()
{
	// basicCinHelper1();
	// basicCinHelper2();
	// basicCinHelper3();
	//  basicCinHelper4();
	basicCinHelper5();
}

void basicCinHelper1()
{
	std::cout<<"\">>\" operator is called formatted extraction operator."<<std::endl;
	
	// leading space will be dumped by cin from cin buffer. 
	std::string str1, str2;
	std::cout<<"Please enter a string, with some leading space: ";
	std::cin>>str1;
	std::cout<<"The string you entered is: "<<str1<<std::endl;

}

void basicCinHelper2()
{

	std::string str1, str2;
	// following whitespace will not be read or dumped by cin. 
	// instead, they will remain in input buffer. 
	// if I try to getline() followed by std::cin, the remaining whitespace 
	// in input buffer will cause trouble
	std::cout<<"Now enter another string: ";
	std::cin>> str1;
	std::cout<<"Please input a small sentence: ";
	std::getline(std::cin, str2);
	std::cout<<"The small sentence you entered: "<<str2<<std::endl;
}

void basicCinHelper3()
{
	std::string str1, str2;
	// solution: std::cin.ignore() can dump one or more characters in input buffer. 
	std::cout<<"Now enter another string for second time: ";
	std::cin>> str1;
	std::cout<<"Please input a small sentence:";
	std::cin.ignore();		// this will ignore one newline character in buffer. 
	std::getline(std::cin, str2);
	std::cout<<"The small sentence you entered: "<<str2<<std::endl;
}

void basicCinHelper4()
{
	// cin may succeed or fail, depending on input. 
	int num = 0;
	while(num != -1)
	{
		std::cout<<"please input letter A:"<<std::endl;
		// this cin will fail since it's trying to get a integer from buffer, 
		//    while a character is on top of buffer. 
		// once cin is failed, it will not read anything, and buffer remains unchanged. 
		std::cin>>num;
	}
}

void basicCinHelper5()
{
	// call cin.clear() to clear fail status of cin. 
	
	int num = 0;
	while(num != -1)
	{
		std::cout<<"please input letter A:"<<std::endl;
		// this cin will fail since it's trying to get a integer from buffer, 
		//    while a character is on top of buffer. 
		// once cin is failed, it will not read anything, and buffer remains unchanged. 
		std::cin>>num;
		
		if(!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

}

void fileIO()
{
	// fileIOWrite();
	
	fileIORead();

}


void fileIOWrite()
{
	// use fstream to create a file stream.
	// fstream supports both read and write. 
	
	// create fstream object	
	// use std::ios::out for output to file (write)
	// use std::ios::in  for input  from file (read)
	// use std::ios::in | std::ios::out for both read and write.
	std::fstream file("inventory.txt", std::ios::out);
	
	// 	if file is good, then write to the file
	if(file)
	{	
		int partNum = 10;
		std::string description = "A power tool.";
		int quantity = 100;
		float unitPrice = 49.99;
		
		file << partNum<<std::endl;
		file << description<<std::endl;
		file << quantity<<std::endl; 
		file << unitPrice <<std::endl;
		
		std::cout<<"Writing file \"inventory.txt\" succeed."<<std::endl;

	}
	else
	{
		std::cout<<"Error when writing to file \"inventory.txt\""<<std::endl;
	}
	
	// close file when done.
	file.close();
}

void fileIORead()
{
	std::fstream file("inventory.txt", std::ios::in);
	
	if(file)
	{
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		// use a loop to keep reading file.
		// if reading file fails, the loop will end
		while(file >> partNum)
		{
			
			file.ignore();
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;	
			
			std::cout<<partNum
				<<"\n"<<description<<"\n"
				<<quantity<<"\n"
				<<unitPrice<<"\n"
				<<std::endl;
		}	
	}
	else
	{
		std::cout<<"Error when reading from file \"inventory.txt\""<<std::endl;
	}
	
	// close file when done
	file.close();
}