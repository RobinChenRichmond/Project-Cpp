#ifndef __NUMBER_C_H__
#define __NUMBER_C_H__

#include "Number.h"

using namespace std;

class Number_c: public Number{
	private:
	int decimal;
	string hexadecimal;
	public:
	Number_c();
	Number_c(int dec_value);
	Number_c(const char* hex_value);
	~Number_c();

	int getDecimalValue();
	char* getBinaryValue();
	char* getHexValue();
	void setValue(int decimal_value);
	void setValue(const char* hex_value);

};

#endif