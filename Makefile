# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
VALGRIND = valgrind --leak-check=full --track-origins=yes

# Targets
all: Ceaser Substitution_Solver Vigenere

Ceaser: Ceaser.o
	$(CC) $(CFLAGS) -o Ceaser Ceaser.o

Ceaser.o: Ceaser.c
	$(CC) $(CFLAGS) -c Ceaser.c

Substitution_Solver: Substitution_Solver.o
	$(CC) $(CFLAGS) -o Substitution_Solver Substitution_Solver.o

Substitution_Solver.o: Substitution_Solver.c
	$(CC) $(CFLAGS) -c Substitution_Solver.c

Vigenere: Vigenere.o
	$(CC) $(CFLAGS) -o Vigenere Vigenere.o

Vigenere.o: Vigenere.c
	$(CC) $(CFLAGS) -c Vigenere.c

clean:
	rm -f *.o Ceaser Substitution_Solver Vigenere

valgrind_Ceaser: Ceaser
	$(VALGRIND) ./Ceaser

valgrind_Substitution_Solver: Substitution_Solver
	$(VALGRIND) ./Substitution_Solver

valgrind_Vigenere: Vigenere
	$(VALGRIND) ./Vigenere

.PHONY: all clean valgrind_Ceaser valgrind_Substitution_Solver valgrind_Vigenere

