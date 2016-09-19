export CXXFLAGS=-g -W -Wall -Werror -pedantic -std=c++11

all: todo

todo: main.o list.o item.o
	g++ $(CXXFLAGS) main.o list.o item.o -o todo

main.o: main.cpp list.h item.h
	g++ $(CXXFLAGS) -c main.cpp

list.o: list.cpp list.h item.h
	g++ $(CXXFLAGS) -c list.cpp

item.o: item.cpp item.h
	g++ $(CXXFLAGS) -c item.cpp

clean:
	rm -f *.o todo

.PHONY: clean
