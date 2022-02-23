# Makefile
CXX_FLAG = --std=c++11 -g

all: testbst

testbst: testbst.o
	g++ $(CXX_FLAG) -o testbst testbst.o

clean:
	rm -f testbst *.o