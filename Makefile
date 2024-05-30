# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
VALGRIND = valgrind --leak-check=full --track-origins=yes

# Targets
all: Ceaser Substitution_Solver Vignette

Ceaser: Ceaser.o
	$(CC) $(CFLAGS) -o Ceaser Ceaser.o

Ceaser.o: Ceaser.c
	$(CC) $(CFLAGS) -c Ceaser.c

Substitution_Solver: Substitution_Solver.o
	$(CC) $(CFLAGS) -o Substitution_Solver Substitution_Solver.o

Substitution_Solver.o: Substitution_Solver.c
	$(CC) $(CFLAGS) -c Substitution_Solver.c

Vignette: Vignette.o
	$(CC) $(CFLAGS) -o Vignette Vignette.o

Vignette.o: Vignette.c
	$(CC) $(CFLAGS) -c Vignette.c

clean:
	rm -f *.o Ceaser Substitution_Solver Vignette

valgrind_Ceaser: Ceaser
	$(VALGRIND) ./Ceaser

valgrind_Substitution_Solver: Substitution_Solver
	$(VALGRIND) ./Substitution_Solver

valgrind_Vignette: Vignette
	$(VALGRIND) ./Vignette

.PHONY: all clean valgrind_Ceaser valgrind_Substitution_Solver valgrind_Vignette

