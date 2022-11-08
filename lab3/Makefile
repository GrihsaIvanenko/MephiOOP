all:
	clear
	g++ -std=c++2a ./myVector/myVector.cpp main.cpp ./lib/sam.cpp
	./a.out

test:
	clear
	g++ apptest.cpp ./lib/sam.cpp ./myVector/myVector.cpp -lgtest -lgtest_main -lpthread
	./a.out
