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

void lambdaFunctionSimple();
void lambdaFunctionWithParam();
void lambdaFunctionWithPointerFunction();

void lambdaFunctionWithVariables();
void uniquePointer();

class Person
{
private:
	string name;
	int age;

public:
	Person() : name(""), age(0)
	{
		cout << " constructor  Person() " << endl;
	}
	Person(const Person &other)
	{
		cout << " Person(const Person &other) " << endl;
		name = other.name;
		age = other.age;
	}
	bool operator<(const Person &other) const
	{
		return name < other.name;
	}

	Person operator=(const Person &other) const
	{
		return *this;
	}

	Person operator=(const Person *other) const
	{
		cout << "------  " << endl;
		other->printSimple();
		cout << "------  " << endl;
		return *other;
	}

	Person(string name, int age) : name(name), age(age)
	{
		cout << " Person(string name, int age) " << endl;
	}

	void print() const
	{
		cout << " { \n \t\t\t Name : " + name + " , Age : " << age << " \n\t\t\t}";
	}

	void printSimple() const
	{
		cout << "  Name : " + name + " , Age : " << age << " \n";
	}

	~Person()
	{
		cout << "Destructor" << endl;
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

	lambdaFunctionSimple();

	lambdaFunctionWithParam();

	lambdaFunctionWithPointerFunction();

	lambdaFunctionWithVariables();

	uniquePointer();

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
	int count = 0;
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
	list.push_back("1four");
	list.push_back("five");
	list.push_back("six");
	list.push_back("seven");
	list.push_back("eight");
	list.push_back("nine");

	cout << "3 CHAR :" << match(list, 3, size) << endl;
	cout << "4 CHAR :" << match(list, 4, size) << endl;
	cout << "5 CHAR :" << match(list, 5, size) << endl;
}

void lambdaFunctionSimple()
{
	auto lFunc = []() {
		cout << " Well a very simple lambda funtion call " << endl;
	};
	lFunc();
}

void lambdaFunctionWithParam()
{
	auto lFunc = [](int aInt, string aStr) {
		cout << "<< " << aInt << aStr << " .. " << endl;
	};
	lFunc(20, "Alec Baldwin");
}

void proxyFuntion(int (*aFunctionPointer)(int, int))
{
	cout << aFunctionPointer(10, 20) << endl;
}

void uniquePointer()
{

	cout << " Regular Start scope " << endl;
	{

		Person *aPerson_pointer = new Person();
		aPerson_pointer->printSimple();
	}
	cout << " End scope " << endl;

	cout << " Unique Start scope " << endl;
	{

		unique_ptr<Person> aPtr_unique_person(new Person);

		(*aPtr_unique_person).printSimple();
	}
	cout << " End scope " << endl;

	cout << " Unique Array Start scope " << endl;
	{

		unique_ptr<Person[]> aPtr_unique_person(new Person[2]);

		//for(int i=0 ;i< 2;i++){

		Person *p1 = new Person("sss", 20);

		aPtr_unique_person[0] = p1;

		aPtr_unique_person[0].printSimple();

		//}

		const char *charArrayPtr = {" Hello how are you "};
		cout << charArrayPtr << endl;
		charArrayPtr = "X";
		cout << charArrayPtr << endl;

		size_t value;

		//cin >> value;

		cout << "\n You have entered " << value << endl;

		//Pointer initializaionß


		// //double* ptr1{};

		// cout << "Ptr with *ptr1{} " << *ptr1 << endl;

		// delete ptr1;

		double *ptr2{new double{}};

		cout << "*ptr2{new double{}} " << *ptr2 << endl;

		delete ptr2;




		//Array 

		double* data {new double[100]{1.2}};

		for(size_t i=0;i<100;i++){

			cout << "i= "<<data[i]<<endl;

		}

		delete [] data;
		data = nullptr;


		// //Two dimensional array pointer 

		// double** carrots{ new double*[2] {} };

		// carrots[1][1]= 5;

		// cout << "[0][0] " << carrots[0][0] <<endl;
		// cout << "[0][1] " << carrots[0][1] <<endl;
		// cout << "[1][0] " << carrots[1][0] <<endl;
		// cout << "[1][1] " << carrots[1][1] <<endl;


		vector<Person>* pData {new std::vector<Person>};

		 

		pData -> push_back(Person("Brady Swain",12));

		(*pData).push_back(Person("Tom Swain",21));







	


	}

	
	cout << " End scope " << endl;

	// cout << " Auto Start scope " << endl;
	// {

	// 	auto<Person> aPtr_unique_person(new Person);

	// 	(*aPtr_unique_person).printSimple();
	// }
	// cout << " End scope " << endl;
}

void lambdaFunctionWithPointerFunction()
{

	auto lfunc = [](int a, int b) -> int {
		if (a > b)
			return a;
		else if (b > a)
			return b;
		else
			return a + b;
	};

	proxyFuntion(lfunc);
}

void lambdaFunctionWithVariables()
{
	//pass value
	{
		int var1 = 100;
		int var2 = 200;
		int var3 = 300;
		//All / by value  /
		auto lfunc = [=]() {
			cout << "var1 = " << var1 << endl;
			cout << "var2 = " << var2 << endl;
			cout << "var3 = " << var3 << endl;
			//var1 =10; wont work
		};
		lfunc();
	}
	//pass refence
	{
		int var1 = 100;
		int var2 = 200;
		int var3 = 300;
		//All / by value  /
		auto lfunc = [&]() {
			var1 = var1 + 1000;
			var2 = var2 + 1000;
			var3 = var3 + 1000;
			cout << "var1 = " << var1 << endl;
			cout << "var2 = " << var2 << endl;
			cout << "var3 = " << var3 << endl;
		};
		lfunc();
	}

	//Mix 1
	{
		int var1 = 100;
		int var2 = 200;
		int var3 = 300;
		//All / by value  /
		auto lfunc = [&, var1]() {
			var2 = var2 + 1000;
			var3 = var3 + 1000;
			cout << "var1 = " << var1 << endl;
			cout << "var2 = " << var2 << endl;
			cout << "var3 = " << var3 << endl;
		};
		lfunc();
	}

	//Mix 2
	{
		int var1 = 100;
		int var2 = 200;
		int var3 = 300;
		//All / by value  /
		auto lfunc = [=, &var1]() {
			var1 = 5000;
			cout << "var1 = " << var1 << endl;
			cout << "var2 = " << var2 << endl;
			cout << "var3 = " << var3 << endl;
		};
		lfunc();
	}
}