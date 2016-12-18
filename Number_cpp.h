#ifndef __NUMBER_CPP_H__
#define __NUMBER_CPP_H__

#include <string>
#include "Number.h"

using namespace std;

class Number_cpp: public Number{
	protected:
	int decimal;
	string hexadecimal;
	public:
	Number_cpp();
	Number_cpp(int dec_value);
	Number_cpp(string hex_value);
	~Number_cpp();

	int getDecimalValue();
	string getBinaryValue();
	string getHexValue();
	void setValue(int decimal_value);
	void setValue(string hex_value);

};

#endif