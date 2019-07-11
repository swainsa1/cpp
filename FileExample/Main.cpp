//============================================================================
// Name        : MyFirstCpp.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct Person
{
	char* name;
	int age;
	double height;
};
string fileName = "testFile.bin";
void createFile();
void readFile();

int main()
{
	system("color F6");

	createFile();
	readFile();

	return 0;
}

void createFile()
{

	Person p1 = {"Tom Hank", 61, 5.7};
	Person p2 = {"Donald Trump", 68, 5.9};
	Person p3 = {"Elizabeth Warren", 55, 6.1};
	Person p4 = {"Jerry Sienfield", 63, 5.11};
	Person p5 = {"Jared Kushner", 35, 5.9};
	Person p6 = {"Bill Gates", 59, 6.2};

	ofstream file;
	file.open(fileName, ios::binary);
	if (file.is_open())
	{

		file.write((char *)&p1, sizeof(Person));
		file.write((char *)&p2, sizeof(Person));
		file.write((char *)&p3, sizeof(Person));
		file.write((char *)&p4, sizeof(Person));
		file.write((char *)&p5, sizeof(Person));
		file.write((char *)&p6, sizeof(Person));
		file.close();
	}
	else
	{
		cout << "Unable to create file " << fileName << endl;
	}
}

void readFile()
{

	ifstream file;
	file.open(fileName, ios::binary);

	if (file.is_open())
	{
		Person p = {};
		system("color FC");
		printf("  %-30s", "---------------------------------------\n");
		printf("| %-20s| %-5s| %-5s   |\n", "Name", "Age", "Height");
		printf("  %-30s", "---------------------------------------\n");
		printf(" %-30s", "---------------------------------------\n");
	

		while (file.read((char *)&p, sizeof(Person)))
		{
			
			printf("| %-20s| %-5d| %-5f|\n", p.name, p.age, p.height);
			printf(" %-30s", "---------------------------------------\n");

		}

		file.close();
	}
	else
	{
		cout << "Unable to open file " << fileName << endl;
	}
}
