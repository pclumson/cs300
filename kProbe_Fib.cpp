// This is a test program that tests some C++ 
//    features we will learn in class.

// to compile: g++ -Wall test.cpp -o test


// ~cs300n/bin/handin 0 test.cpp 




#include <iostream>

using namespace std;

void question2()
{
	// test the module operator % 
	// cout << "5 % 2 = "<<5%2<<endl; 
	
	int result = 0;
	int result1 = 0;
	
	for (int i = 0; i < = 100; i++)
	{
		if (i % 2 == 1)	// this i is odd number
			result = result + i;
		else 
			resutl1 += i;	// this is is even number
	}
	
	cout<< "result is: "<< result<< endl;
	
	cout<< "result is (even case): "<< result1<< endl;
	
}


void question3()
{
	char char1, char2;     
    int num1, num2;     
    float value; 
    cout << "enter something: ";     // a 12 13.5 b 22.2 is entered 
    cin >> char1;     
    cin >> num1;     
    cin >> num2; 
    cin >> char2;     
    cin >> value; 
	
	cout<<char1<<endl;
	cout<<num1<<endl;
	cout<<num2<<endl;
	cout<<char2<<endl;
	cout<<value<<endl;

}


double question4(double length, double width, double price, double discount)
{
	return length * width * price * ((100 - discount)/100);
}


// this is the function to calc fib number 
//  given position by user.
// int pos: the positive position given by user
int fib(int pos)
{
	// for error postion 
	if (pos < = 0)
	{
		cout<< "Illegal position. Position must be positive."<<endl;
		return -1;
	}
	
	// trivial cases for fib num
	if (pos == 1 || pos == 2)
	{
		return 1;
	}
	
	// when position is greater than 2
	int num1 = 1;
	int num2 = 1;
	int result = 0;
	for (int i = 3; i <= pos; i++)
	{
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}
	
	// cout<< "The "<< pos<<" Fib number is: "<< result<<endl; 
	
	return result;
}

int fib2(int pos)
{
	if (pos == 1 || pos ==2)
		return 1;
	else
		return fib2(pos - 1) + fib2(pos - 2);
}






int main()
{
	// question2();
	// question3();
	/*
	cout<<"Enter length:";
	double length;
	cin >> length;
	
	cout<<"Enter width: ";
	double width;
	cin >> width;
	
	cout<<"Enter price: "
	double price;
	cin >> price;
	
	cout<<"Enter discount: "
	double discount;
	cin >> discount;
	*/
	
	// cout << "Total price: "<< question4(length, width, price, discount);
	
	for (int i = 1; i < 50; i++)
		cout<<"Fib ("<< i <<") = "<<fib2(i)<<endl;
	
	
	return 0;
}


