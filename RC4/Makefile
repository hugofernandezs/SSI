# Vigenere makefile.


### VARIABLES ###

PROJECT_ROOT	:= /home/siga01.stic.ull.es/12/alu0101112664/SSI/RC4/

CC		:= g++ -g -std=c++17 -Wall -Wextra
CCO		:= g++ -g -std=c++17 -Wall -Wextra -c

EXE		:= $(PROJECT_ROOT)/bin/rc4.exe

MAIN	:= $(PROJECT_ROOT)/src/rc4.cpp

VIG.H	:= $(PROJECT_ROOT)/src/Rc4Cipher.h
VIG.O	:= $(PROJECT_ROOT)/src/Rc4Cipher.o
VIG.C	:= $(PROJECT_ROOT)/src/Rc4Cipher.cpp





### FUNCTIONS ###

all: $(VIG.O)
	$(CC) $(MAIN) $^ -o $(EXE)

$(VIG.O): $(VIG.C) $(VIG.H)
	$(CCO) $< -o $(VIG.O)

clean:
	-find . -name "*.o" -type f -delete
	-find . -name "*.out" -type f -delete