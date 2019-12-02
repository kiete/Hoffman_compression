all: hoffman.exe

hoffman.exe: main.c caractere.o
	clang main.c caractere.o -o hoffman.exe

caractere.o: caractere.c
	clang -c caractere.c