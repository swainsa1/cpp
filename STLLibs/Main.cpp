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

void printMap(map<int, Person> map);
void matrixVector();
void listExample();
void mapExample();
void printMap(map<int, Person> map);
void printList(list<int> list1);
void addToList(list<int> list1, int value);
list<int> removeFromeList(list<int> list1, int value);

void setExample();

void stackExample();

void queueExample();

void sortVector();

void sortVectorByComparator();

int main()
{
	matrixVector();
	listExample();
	mapExample();
	setExample();
	stackExample();
	queueExample();
	sortVector();
	sortVectorByComparator();
	return 0;
}

bool compByAge(const Person aPerson, Person anotherPerson)
{
	return aPerson.age < anotherPerson.age;
}

bool compByAgeDesc(const Person aPerson, Person anotherPerson)
{
	return aPerson.age > anotherPerson.age;
}

void sortVectorByComparator()
{

	cout << " ######################   Sort Vector  Example  Comparator ###################" << endl;

	vector<Person> unsortedList;

	unsortedList.push_back(Person("Zeeva	advani", 44));

	unsortedList.push_back(Person("Zeeva	advani", 44));
	unsortedList.push_back(Person("Minn Zero", 23));
	unsortedList.push_back(Person("LK Mishra", 24));
	unsortedList.push_back(Person("Anand	advani", 43));
	unsortedList.push_back(Person("Jeevan Mihg", 55));
	unsortedList.push_back(Person("Zeevan advani", 33));

	//Print the unsorted list
	cout << " Before Sorting " << endl;
	for (int index = 0; index < unsortedList.size(); index++)
	{
		unsortedList[index].printSimple();
	}

	cout << " Sort by age " << endl;
	sort(unsortedList.begin(), unsortedList.end(), compByAge);

	cout << " After Sorting " << endl;
	for (int index = 0; index < unsortedList.size(); index++)
	{
		unsortedList[index].printSimple();
	}

	cout << " Sort by age desc" << endl;
	sort(unsortedList.begin(), unsortedList.end(), compByAgeDesc);

	cout << " After Sorting " << endl;
	for (int index = 0; index < unsortedList.size(); index++)
	{
		unsortedList[index].printSimple();
	}


}

void sortVector()
{
	cout << " ######################   Sort Vector  Example ###################" << endl;

	vector<Person> unsortedList;

	unsortedList.push_back(Person("Zeeva	advani", 44));

	unsortedList.push_back(Person("Zeeva	advani", 44));
	unsortedList.push_back(Person("Minn Zero", 23));
	unsortedList.push_back(Person("LK Mishra", 24));
	unsortedList.push_back(Person("Anand	advani", 43));
	unsortedList.push_back(Person("Jeevan Mihg", 55));
	unsortedList.push_back(Person("Zeevan advani", 33));

	//Print the unsorted list
	cout << " Before Sorting " << endl;
	for (int index = 0; index < unsortedList.size(); index++)
	{
		unsortedList[index].printSimple();
	}

	cout << " Sort by name " << endl;
	sort(unsortedList.begin(), unsortedList.end());

	cout << " After Sorting " << endl;
	for (int index = 0; index < unsortedList.size(); index++)
	{
		unsortedList[index].printSimple();
	}
}

void queueExample()
{

	cout << " ######################   Queue  Example ###################" << endl;
	queue<Person> serviceQueue;
	serviceQueue.push(Person("AAAA", 23)); //1st element
	serviceQueue.push(Person("BBB", 43));  //2nd element
	serviceQueue.push(Person("CCC", 56));  //3rd
	serviceQueue.push(Person("DDDD", 67)); //4th
	serviceQueue.push(Person("EEEE", 78)); //5th
	Person front = serviceQueue.front(); //1st
	cout << "front = " << flush;
	front.printSimple(); //1st

	Person back = serviceQueue.back(); //6thnd is at the front now
	cout << "back = " << flush;
	back.printSimple();

	serviceQueue.pop(); // 1st is gone

	front = serviceQueue.front(); //2nd is at the front now
	cout << "front = " << flush;
	front.printSimple();

	serviceQueue.push(Person("1111111", 78)); //6th

	cout << "back = " << flush;
	back = serviceQueue.back(); //6thnd is at the front now

	back.printSimple();
}

void stackExample()
{

	cout << " ######################   Stack  Example ###################" << endl;
	stack<Person> stackOfPerson;

	stackOfPerson.push(Person("AAAA", 23)); //1st element
	stackOfPerson.push(Person("BBB", 43));  //2nd element
	stackOfPerson.push(Person("CCC", 56));  //3rd
	stackOfPerson.push(Person("DDDD", 67)); //4th
	stackOfPerson.push(Person("EEEE", 78)); //5th

	//Find the top element
	Person top = stackOfPerson.top(); //5th
	top.printSimple();

	//pop one element
	stackOfPerson.pop(); //5th gone
	//Find the top again
	top = stackOfPerson.top(); //4th

	top.printSimple(); //4th
}
void mapExample()
{

	map<int, Person> person_map;
	person_map[1001] = Person("Alex Misso", 40);
	person_map[1002] = Person("Joane Buter", 38);
	person_map[1003] = Person("Minnea polis", 43);
	person_map[1004] = Person("Jaha bulder", 85);

	person_map.insert(make_pair(1005, Person("Utsav Fasino", 55)));

	printMap(person_map);
}

void setExample()
{

	cout << " ######################   Set Example " << endl;
	set<Person> unquieList;

	unquieList.insert(Person("Zeeva	advani", 44));
	unquieList.insert(Person("Minn Zero", 23));
	unquieList.insert(Person("LK Mishra", 24));
	unquieList.insert(Person("Anand	advani", 43));
	unquieList.insert(Person("Jeevan Mihg", 55));
	unquieList.insert(Person("Zeevan advani", 33));

	for (set<Person>::iterator it = unquieList.begin(); it != unquieList.end(); it++)
	{
		it->print();
	
	}
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
			list1.push_back(*it_modify + 500);
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

void printMap(map<int, Person> person_map)
{
	cout << " Map Size[" << person_map.size() << "] { ";
	for (map<int, Person>::iterator it = person_map.begin(); it != person_map.end(); it++)
	{

		cout << "\n\t\t" << it->first << " : " << flush;
		it->second.print();
	}
	cout << " \n\t} " << endl;
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
