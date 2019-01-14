#Makefile for: "Lab 7" C++ application
#Created by: Daniel Snow
#Date: November 11, 2018

Lab7CLLists: CircularLLists.o programMenu.o CLinkedList.o
	g++ -std=c++11 CircularLLists.o programMenu.o CLinkedList.o -o Lab7CLLists

CircularLLists.o: CircularLLists.cpp
	g++ -std=c++11 -c CircularLLists.cpp

programMenu.o: programMenu.cpp programMenu.hpp
	g++ -std=c++11 -c programMenu.cpp

CLinkedList.o: CLinkedList.cpp CLinkedList.hpp
	g++ -std=c++11 -c CLinkedList.cpp

clean:
	rm *.o Lab7CLLists

