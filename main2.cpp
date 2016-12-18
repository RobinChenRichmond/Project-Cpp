#include <iostream>
#include <string>
#include "Number_c.h"

using namespace std;

int main(){
	Number_c* my_number = new Number_c(867); // or new Number_cpp("363")
	cout << my_number->getDecimalValue() << " "
	<< my_number->getBinaryValue() << " "
	<< my_number->getHexValue() << endl;


	my_number->setValue("14BD"); // or setValue(5309)

	cout << my_number->getDecimalValue() << " "
	<< my_number->getBinaryValue() << " "
	<< my_number->getHexValue() << endl;
	
	delete my_number;
}