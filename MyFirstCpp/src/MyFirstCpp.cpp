//============================================================================
// Name        : MyFirstCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>

using namespace std;

int main() {
	cout << "Starting " << endl; 

	int variable = 20;

	int* pVariable = &variable;
	cout << "Variable value ="<< pVariable << endl;
	


	return 0;
}
