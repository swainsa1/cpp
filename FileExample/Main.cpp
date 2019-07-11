//============================================================================
// Name        : MyFirstCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
void createFile(ofstream file,vector<Person> personList );
void readFile(string fileName);

struct Person {
	string name;
	int age;
	double height;
};
int main() {

	string fileName ="testFile.bin";

	vector<Person> personList(10);
	
	Person p1 = {"Santosh Swain",30,5.7};
	Person p2 = {"Siyona Swain",7,3.7};
	Person p3 = {"Samarth Swain",5,3.7};
	Person p4 = {"Rojalin Swain",30,5.2};
	Person p5 = {"Saroj Swain",25,5.4};
	Person p6 = {"Suresh Swain",28,5.7};

	personList.push_back(p1);
	personList.push_back(p2);
	personList.push_back(p3);
	personList.push_back(p4);
	personList.push_back(p5);
	personList.push_back(p6);
	
	ofstream file ;


   file.open(fileName,ios::binary);
	if(file.is_open()){
		createFile(file,personList);
		
	}

	
    
    readFile("Test");


	return 0;
}


void createFile(ofstream file,vector<Person> personList ){

   for (size_t i = 0; i < personList.size(); i++)
   {
	   file.write((char *)&personList[i],sizeof(Person));
   }
   

}

void readFile(string fileName){

cout << " FileName:  " << fileName <<endl;


}
