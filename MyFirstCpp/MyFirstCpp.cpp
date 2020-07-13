//============================================================================
// Name        : MyFirstCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<locale.hpp>

using namespace std;
void passByValue(int value);
void passByReference(int* value);
void localeTest();
int main() {
	cout << "Starting " << endl; 

	int var = 20;

	
	cout << "Main .1 . "<< var << endl;

     passByReference(&var);
     cout << "Main 2 . " << var << endl;;
     passByValue(var);
	 cout << "Main  . " << var << endl;;

	 localeTest();
	return 0;
}

class A;


class A {
   int id;
   std::variant<int,unique_ptr<A()>> var;
};
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


void localeTest(){

  std::locale defaultLocale;     // the "C" locale
  defaultLocale.global(std::locale(""));
  cout << "-------" << defaultLocale.name()<<endl;


  		setlocale(LC_ALL, "");
    cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << endl;
    cout << "LC_CTYPE: " << setlocale(LC_CTYPE, NULL) << endl;
    
 using namespace boost::locale;
    using namespace std;
    generator gen;
    // Make system default locale global
    std::locale loc = gen("");
	cout << "-------" << loc.name()<<endl;


}
