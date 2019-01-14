#Makefile for War program, plays a game of war with dice
War: WarGame.o programMenu.o playWarGame.o Die.o LoadedDie.o
	g++ -std=c++11 WarGame.o programMenu.o playWarGame.o Die.o LoadedDie.o -o War

WarGame.o: WarGame.cpp
	g++ -std=c++11 -c WarGame.cpp

programMenu.o: programMenu.cpp programMenu.h
	g++ -std=c++11 -c programMenu.cpp

playWarGame.o: playWarGame.cpp playWarGame.h
	g++ -std=c++11 -c playWarGame.cpp

Die.o: Die.cpp Die.h
	g++ -std=c++11 -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.h
	g++ -std=c++11 -c LoadedDie.cpp

clean:
	rm *.o War


