test : utils.o tester.o point.o
	g++ -g -o tester tester.o utils.o point.o

residue: residue.o
	g++ -g -o residue residue.o

residue.o : residue.cpp
	g++ -g -c residue.cpp

utils.o : utils.h utils.cpp
	g++ -g -c utils.cpp

point.o : point.h point.cpp
	g++ -g -c point.cpp

tester.o : tester.cpp
	g++ -g -c tester.cpp
