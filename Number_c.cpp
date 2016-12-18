#include <iostream>
#include <math.h>
#include <string.h>
#include "Number_c.h"

using namespace std;

Number_c::Number_c():decimal(-1),hexadecimal(""){};

Number_c::Number_c(int dec_value){
	decimal = dec_value;
	hexadecimal = "";
};

Number_c::Number_c(const char* hex_value){
	decimal = -1;
	hexadecimal = hex_value;
};
Number_c::~Number_c(){};

int Number_c::getDecimalValue(){
	if(hexadecimal == "0"){
		return 0;
	}
	if(hexadecimal == ""){
		return decimal;
	} else{
		int result = 0;
		int length = 0;
		while(hexadecimal[length] != '\0'){
			length++;
		}

		int digit = length-1;

		const char* hexTable = "0123456789ABCDEF";
		for(int i = 0; i < length; i ++){
			for(int j = 0; j< strlen(hexTable); j ++){
				if(hexadecimal[i] == hexTable[j]){
					result = result + j*pow(16,digit);
					digit --;
					break;
				}
			}
		}

		return result;
	}
};

char* Number_c::getBinaryValue(){
	if(hexadecimal == "0" || decimal == 0){
		char* result = (char*) malloc(2);
		result[0] = '0';
		result[1] = '\0';
		delete result;
		return result;
	}
	if(decimal != -1){
		int tempDecimal = decimal;
		int counter = 0;
		while(tempDecimal > 0){
			tempDecimal = tempDecimal/2;
			counter ++;
		}
		tempDecimal = decimal;

		char* result = (char*) malloc(counter+1);

		int index = counter-1;
		while(tempDecimal > 0){
			if(tempDecimal%2 == 1){
				result[index] = '1';
			} else{
				result[index] = '0';
			}
			index--;
			tempDecimal = tempDecimal/2;
		}
		result[counter] = '\0';
		delete result;
		return result;
	} else {
		decimal = this->getDecimalValue();
		int tempDecimal = decimal;
		int counter = 0;
		while(tempDecimal > 0){
			tempDecimal = tempDecimal/2;
			counter ++;
		}
		tempDecimal = decimal;

		char* result = (char*) malloc(counter+1);

		int index = counter-1;
		while(tempDecimal > 0){
			if(tempDecimal%2 == 1){
				result[index] = '1';
			} else{
				result[index] = '0';
			}
			index--;
			tempDecimal = tempDecimal/2;
		}
		result[counter] = '\0';
		delete result;
		return result;
	}
};

char* Number_c::getHexValue(){
	if(hexadecimal == "0" || decimal == 0){
		char* result = (char*) malloc(2);
		result[0] = '0';
		result[1] = '\0';
		delete result;
		return result;
	}
	if(decimal == -1){
		int length = 0;
		while(hexadecimal[length] != '\0'){
			length++;
		}
		char* result = new char[length+1];
		for(int i = 0; i < length; i ++){
			result[i] = hexadecimal[i];
		}
		result[length] = '\0';
		delete result;
		return result;
	}
	int counter = 0;
	int tempDecimal = decimal;
	while(tempDecimal > 0){
		tempDecimal = tempDecimal/16;
		counter ++;
	}
	tempDecimal = decimal;

	char* result = (char*) malloc(counter+1);
	const char* hexTable = "0123456789ABCDEF";

	int secondCounter = counter-1;
	while(tempDecimal > 0){
		for(int i = 0;i < strlen(hexTable); i ++){
			if(tempDecimal%16 == i){
				result[secondCounter] = hexTable[i];
				secondCounter--;
				break;
			}
		}
		tempDecimal = tempDecimal/16;
	}
	result[counter] = '\0';
	delete result;
	return result;
};

void Number_c::setValue(int decimal_value){
	decimal = decimal_value;
	hexadecimal = "";

};

void Number_c::setValue(const char* hex_value){
	hexadecimal = hex_value;
	decimal = -1;
};



