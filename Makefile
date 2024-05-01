EXE_NAME := MathParse

test: |build/ build/functions.o build/tests.o
	${CXX} -o build/${EXE_NAME}_test build/tests.o build/functions.o

build/tests.o: src/tests.cpp
	${CXX} ${CXXFLAGS} -c src/tests.cpp -o $@

build/functions.o: src/functions.cpp
	${CXX} ${CXXFLAGS} -c src/functions.cpp -o $@

build/:
	@echo "Could not find ./build, creating it now"
	mkdir build
