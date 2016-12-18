#include <iostream>
#include <fstream> 
#include <string>
#include "Number_cpp.h"

using namespace std;

void sortArray(Number_cpp *a[],int size){
	// create an integer array
	int num[size]; 

	// load the data of Number_cpp into the integer array
	for(int i = 0; i < size; i ++){ 
		num[i] = a[i]->getDecimalValue();
	}
	std::sort(num,num+size);

	// put the sorted integer back into the Number_cpp array
	for(int i = 0;i < size; i ++){
		a[i]->setValue(num[i]);
	}
}

int main(int argc, char *argv[]){
	ifstream inputFile;
	ofstream outputFile;

	if(argc < 3)
	{
		cerr<<"Usage: "<<argv[0]<<" [input file] [output file]"<<endl;
		exit(1);
	}
	inputFile.open(argv[1]);
	if ( !inputFile.is_open() )
   	{
        // open file and check that it was successfully opened
        cerr << "Error: Unable to open file " << argv[1] << endl;
        exit(1);
    }

    // set variables
    const int numOfInput = 512;
    Number_cpp *my_number[numOfInput];
	int leftInput = numOfInput;
	
	while(inputFile.good() && leftInput > 0)
	{
		int temp = 0;
		inputFile >> temp; // read an integer
		my_number[numOfInput-leftInput] = new Number_cpp(temp);

		
		if ( inputFile.fail() )
        {
            // If the fail flag is set by >>, something unexpected happened:
            //    e.g., wrong data type in file for reading;
            //    e.g., only thing left to read is end-of-file character 
            // If the former, one could (should) print an error message;
            // if the latter, the .eof() method can be used to identify and
            // break out.
            if (inputFile.eof())
            {
            	// no problem here -- just exit loop and handle results
                break;
			}
           	else
			{
                // failed for some other reason (e.g., string or float input);
                // print a message and exit
                cerr << "There's an error while reading an integer datum..." << endl;
                exit(1);
            }
            break;
        }
        leftInput--;
	}
	inputFile.close();
	// sort the created array
	sortArray(my_number,numOfInput-leftInput);
	outputFile.open(argv[2]);

	// write the sorted array into the output file
	for(int i = 0;i<numOfInput-leftInput;i++){
		outputFile << my_number[i]->getDecimalValue() << "\t"
		<< my_number[i]->getBinaryValue() << "\t"
		<< my_number[i]->getHexValue() << endl;
	}

	outputFile.close();
	delete *my_number;
}