Programmer: Robin Chen

README:

To test each part of the project, I create three Makefile files called Makefile, Makefile2, Makefile3.

With command “make -f Makefile(2,3)” we create files main, main2 and ReadDecimal to execute. Executing main and main2 helps me go through the codes in main.cpp and main2.cpp, and make sure that Number_cpp.cpp and Number_c.cpp work and get correct output. Executing ReadDecimal with arguments input(2,3).txt output(2,3).txt helps me go through the codes in ReadDecimal.cpp and make sure that it works correctly by comparing the input and output files.

For the ReadDecimal part, I randomly put more than 10 positive integers in input.txt, and the answer is in order and correct. 
Then for input2.txt I put more integers and also some large integers, and test that it works as well. 
For input3.txt, I put integer 1 and integer0, the answer in output3.txt is “1	1	1” and “0	0	0”, which means that it also works in some special cases.