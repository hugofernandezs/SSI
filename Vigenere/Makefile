# Vigenere makefile.


### VARIABLES ###

PROJECT_ROOT	:= D:\Home\Universidad\SSI\Vigenere

CC		:= g++ -g -std=c++20 -Wall -Wextra
CO		:= g++ -g -std=c++20 -Wall -Wextra -c

EXE		:= $(PROJECT_ROOT)\bin\vigenere.exe

MAIN	:= $(PROJECT_ROOT)\src\vigenere.cpp




### FUNCTIONS ###

all:
	$(CC) $(MAIN) -o $(EXE)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.out" -type f -delete