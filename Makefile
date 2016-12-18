CC = g++
LD = $(CC)

main: main.o
	$(LD) -o main Number.o Number_cpp.o main.o

Number_cpp.o: Number_cpp.cpp Number_cpp.h Number.h Number.cpp
	$(CC) -c Number_cpp.cpp

Number.o: Number.h Number.cpp
	$(CC) -c Number.cpp

main.o: Number.o Number_cpp.o main.cpp
	$(CC) -c main.cpp

clean:
	/bin/rm -f *.o main main2 ReadDecimal