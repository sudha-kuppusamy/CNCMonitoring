all:
	g++ -Wall -Wextra -o testData src/*.cpp *.cpp -Iinclude -Isrc -lgtest -lpthread 
