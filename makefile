CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
C11 = --std=c++11
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
BIN = -o bin
FILES = src/Base.cc src/Command.cc src/Interface.cc src/main.cc

all: rshell
	
rshell: base
	$(CC) $(CC_FLAGS) $(FILES) $(C11)
	mv a.out bin

base:
	mkdir bin 
	chmod 777 bin