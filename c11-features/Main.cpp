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
#include <map>
#include <stdlib.h>
#include <set>
#include <stack>
#include <queue>

using namespace std;

//Define methods

void enhancedForLoop();

void functionPointer();

class Person
{
private:
	string name;
	int age;

public:
	Person() : name(""), age(0)
	{
	}
	Person(const Person &other)
	{
		name = other.name;
		age = other.age;
	}
	bool operator<(const Person &other) const
	{
		return name < other.name;
	}

	Person(string name, int age) : name(name), age(age) {}

	void print() const
	{
		cout << " { \n \t\t\t Name : " + name + " , Age : " << age << " \n\t\t\t}";
	}

	void printSimple() const
	{
		cout << "  Name : " + name + " , Age : " << age << " \n";
	}

	friend bool compByAge(const Person aPerson, Person anotherPerson);
	friend bool compByAgeDesc(const Person aPerson, Person anotherPerson);
};

int main()
{
	cout << "C++ 11 features " << endl;

	auto var = 7;
	cout << var << endl;

	auto str = "Hello";
	cout << str << endl;

	enhancedForLoop();

	functionPointer();

	return 0;
}

void enhancedForLoop()
{
	vector<string> list;
	list.push_back("one");
	list.push_back("two");
	list.push_back("three");
	list.push_back("four");
	list.push_back("five");

	for (auto var : list)
	{
		cout << var << endl;
	}
}

bool size(string str, int len)
{
	return str.length() == len;
}

int match(vector<string> &strList, int len1, bool (*aMethodRef)(string str, int len2))
{
	int count=0;
	for (auto str1 : strList)
	{
		if (aMethodRef(str1, len1))
		{
			count++;
		}
	}
	return count;
}

void functionPointer()
{
	vector<string> list;
	list.push_back("one");
	list.push_back("two");
	list.push_back("three");
	list.push_back("four");
	list.push_back("five");
	list.push_back("six");
	list.push_back("seven");
	list.push_back("eight");
	list.push_back("nine");


	cout << "3 CHAR :" << match(list, 3, size) << endl;
	cout << "4 CHAR :" << match(list, 4, size) << endl;
	cout << "5 CHAR :" << match(list, 5, size) << endl;

	
}