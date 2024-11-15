CXX_FLAGS = -std=c++20 -Ofast

all: testHash

testHash: MHashMap.o main.cpp
	${CXX} $^ -o $@

MHashMap.o: MHashMap.h MHashMap.cpp
	g++ -c $(CXX_FLAGS) MHashMap.cpp

clean:
	rm -f *.o
	rm -f testHash