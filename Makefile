all: hoffman.exe test.exe

ecriture.o: ecriture.c ecriture.h
	gcc -c ecriture.c

caractere.o: caractere.c
	gcc -c caractere.c

arbre.o: arbre.c arbre.h
	gcc -c arbre.c

codage.o: codage.c codage.h
	gcc -c codage.c

test.exe: main_codage.c caractere.o arbre.o codage.o
	gcc main_codage.c caractere.o codage.o arbre.o -o test.exe

hoffman.exe: main_compression.c caractere.o arbre.o codage.o ecriture.o
	gcc main_compression.c caractere.o arbre.o codage.o ecriture.o -o hoffman.exe

clean: 
	rm *.o