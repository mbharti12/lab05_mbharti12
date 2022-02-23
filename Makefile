# Makefile
CXX_FLAG = --std=c++11 -g

all: testbst

testbst: testBST.o
	g++ $(CXX_FLAG) -o testBST testBST.o

clean:
	rm -f testBST *.o