
### VARIABLES ###

PROJECT_ROOT	:= $(realpath .)

CC		:= g++ -g -std=c++17 -Wall -Wextra
CCO		:= g++ -g -std=c++17 -Wall -Wextra -c

EXE		:= $(PROJECT_ROOT)/bin/chacha.exe

MAIN	:= $(PROJECT_ROOT)/src/main.cpp

VIG.H	:= $(PROJECT_ROOT)/src/chachaCipher.h
VIG.O	:= $(PROJECT_ROOT)/src/chachaCipher.o
VIG.C	:= $(PROJECT_ROOT)/src/chachaCipher.cpp





### FUNCTIONS ###

all: $(VIG.O)
	$(CC) $(MAIN) $^ -o $(EXE)

$(VIG.O): $(VIG.C) $(VIG.H)
	$(CCO) $< -o $(VIG.O)

clean:
	-find . -name "*.o" -type f -delete
	-find . -name "*.out" -type f -delete