#include <iostream>
#include <math.h>
#include "Number_cpp.h"

using namespace std;

Number_cpp::Number_cpp():decimal(-1),hexadecimal(""){};

Number_cpp::Number_cpp(int dec_value){
	decimal = dec_value;
	hexadecimal = "";
};

Number_cpp::Number_cpp(string hex_value){
	decimal = -1;
	hexadecimal = hex_value;
};
Number_cpp::~Number_cpp(){};

int Number_cpp::getDecimalValue(){
	if(hexadecimal == "0"){
		return 0;
	}
	if(hexadecimal == ""){
		return decimal;
	} else{
		int result = 0;
		int length = hexadecimal.length();
		int digit = length-1;
		string hexTable = "0123456789ABCDEF";
		for(int i = 0; i < length; i ++){
			for(int j = 0; j< hexTable.length(); j ++){
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

string Number_cpp::getBinaryValue(){
	string result = "";
	if(hexadecimal == "0" || decimal == 0){
		result = "0";
		return result;
	}
	
	if(decimal != -1){
		int tempDecimal = decimal;
		while(tempDecimal > 0){
			if(tempDecimal%2 == 1){
				result = '1' + result;
			} else{
				result = '0' + result;
			}
			tempDecimal = tempDecimal/2;
		}
	} else {
		decimal = this->getDecimalValue();
		int tempDecimal = decimal;
		while(tempDecimal > 0){
			if(tempDecimal%2 == 1){
				result = '1' + result;
			} else{
				result = '0' + result;
			}
			tempDecimal = tempDecimal/2;
		}
	}
	return result;
};

string Number_cpp::getHexValue(){
	string result = "";
	if(decimal == -1){
		return hexadecimal;
	}
	if(decimal == 0){
		result = "0";
		return result;
	}
	int tempDecimal = decimal;
	string hexTable = "0123456789ABCDEF";
	while(tempDecimal > 0){
		for(int i = 0;i < hexTable.length(); i ++){
			if(tempDecimal%16 == i){
				result = hexTable[i] + result;
				break;
			}
		}
		tempDecimal = tempDecimal/16;
	}
	return result;
};

void Number_cpp::setValue(int decimal_value){
	decimal = decimal_value;
	hexadecimal = "";

};

void Number_cpp::setValue(string hex_value){
	hexadecimal = hex_value;
	decimal = -1;
};



