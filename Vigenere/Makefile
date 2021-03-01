# Vigenere makefile.


### VARIABLES ###

PROJECT_ROOT	:= /mnt/d/Home/Universidad/SSI/Vigenere/

CC		:= g++ -g -std=c++17 -Wall -Wextra
CCO		:= g++ -g -std=c++17 -Wall -Wextra -c

EXE		:= $(PROJECT_ROOT)/bin/vigenere.exe

MAIN	:= $(PROJECT_ROOT)/src/vigenere.cpp

VIG.H	:= $(PROJECT_ROOT)/src/VigenereCipher.h
VIG.O	:= $(PROJECT_ROOT)/src/VigenereCipher.o
VIG.C	:= $(PROJECT_ROOT)/src/VigenereCipher.cpp





### FUNCTIONS ###

all: $(VIG.O)
	$(CC) $(MAIN) $^ -o $(EXE)

$(VIG.O): $(VIG.C) $(VIG.H)
	$(CCO) $< -o $(VIG.O)

clean:
	-find . -name "*.o" -type f -delete
	-find . -name "*.out" -type f -delete