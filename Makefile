CXX = g++
EXE_NAME := MathParse

test: |build/ build/tests.o build/functions.o
	${CXX} -o build/${EXE_NAME}_test build/tests.o build/functions.o

build/tests.o:
	${CXX} ${CXXFLAGS} -c src/tests.cpp -o $@

build/functions.o:
	${CXX} ${CXXFLAGS} -c src/functions.cpp -o $@

build/:
	mkdir build
