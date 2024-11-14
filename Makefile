CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BINARIES=testStudent testRoster1 testRoster2 testRoster3

all: ${BINARIES}

testStudent: testStudent.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster1: testRoster1.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster2: testRoster2.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster3: testRoster3.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testStudent
	./testRoster1
	./testRoster2
	./testRoster3

clean:
	/bin/rm -f ${BINARIES} *.o