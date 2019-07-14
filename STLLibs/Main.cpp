//============================================================================
// Name        : Main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : This program creates a binary file and stores all the content of a custom object into it
// Then reads the file back and displays data in a table format
//============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;

void matrixVector();
void listExample();
void printList(list<int> list1);
void addToList(list<int> list1, int value);
list<int> removeFromeList(list<int> list1, int value);

int main()
{
	matrixVector();
	listExample();

	return 0;
}

void listExample()
{
	list<int> list1;
	list1.push_back(1011);
	list1.push_back(1021);
	list1.push_back(1031);
	list1.push_back(1041);
	list1.push_back(1051);
	list1.push_back(1061);
	list1.push_back(1071);
	list1.push_back(1081);

	//Print out all the element
	// for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
	// {

	// 	cout << "|" << *it << "|" << endl;
	// }

	printList(list1);

	//Remove 103
	for (list<int>::iterator it_modify = list1.begin(); it_modify != list1.end(); it_modify++)
	{

		if (*it_modify == 1031 || *it_modify == 1051 || *it_modify == 1081)
		{
			list1.push_back(*it_modify+500);
			list1.erase(it_modify);
			
		}

			
	}





	printList(list1);
}

void printList(list<int> list1)
{
	cout << " List Size[" << list1.size() << "] { ";
	for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
	{

		cout << *it << " ";
	}
	cout << " } " << endl;
}

void matrixVector()
{
	cout << "Matrix Example using Vector" << endl;

	vector<vector<int> > matrix(5, vector<int>(5, 5));

	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix[row].size(); col++)
		{
			cout << "|" << matrix[row][col] << "|" << flush;
		}
		cout << endl;
	}

	cout << "Vector Example" << endl;
}
