//============================================================================
// Name        : MyFirstCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>

using namespace std;
void passByValue(int value);
void passByReference(int* value);
int main() {
	cout << "Starting " << endl; 

	int var = 20;

	
	cout << "Main .1 . "<< var << endl;

     passByReference(&var);
     cout << "Main 2 . " << var << endl;;
     passByValue(var);
	 cout << "Main  . " << var << endl;;
	return 0;
}


void passByValue(int value){
 cout << "passByValue . 1 .Received value = " << value << endl;;
 value = 100 ;
 cout << "passByValue . 2 .Reset value = " << value << endl;; 
}

void passByReference(int* value){
 cout << "passByReference 1. Received value = " << *value << endl;;
 *value = 500 ;
 cout << "passByReference 2 .Reset value = " << *value << endl;; 

}
