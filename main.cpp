#include <iostream>
#include <string>
#include "Number_cpp.h"

using namespace std;

int main(){
	
	Number_cpp* my_number = new Number_cpp(867); // or new Number_cpp("363")
	cout << my_number->getDecimalValue() << " "
	<< my_number->getBinaryValue() << " "
	<< my_number->getHexValue() << endl;


	my_number->setValue("14BD"); // or setValue(5309)

	cout << my_number->getDecimalValue() << " "
	<< my_number->getBinaryValue() << " "
	<< my_number->getHexValue() << endl;

	delete my_number;
}