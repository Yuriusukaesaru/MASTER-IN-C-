#CALIZ DEL MAKEFILE

ifeq ($(OS), Windows_NT)
EXT := .exe
else ifeq ($(shell uname), Linux)
EXT :=
endif

all: bin bin/prog.exe

bin:
	mkdir bin

bin/prog.exe: src/main.cpp src/meth.cpp src/Person.hpp
	g++ -g -Wall -Wextra -Wpedantic -Werror \
			-std=c++20 src/main.cpp src/meth.cpp -o bin/prog$(EXT)

.PHONY: clean
clean:
	rm bin/* main.obj