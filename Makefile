CC = clang
CCOPTS = -Wall

all: hoffman.exe test.exe

ecriture.o: ecriture.c ecriture.h
	clang -c ecriture.c

caractere.o: caractere.c
	clang -c caractere.c

arbre.o: arbre.c arbre.h
	clang -c arbre.c

liste_ext.o: liste_ext.c liste_ext.h listes.h
	${CC} ${CCOPTS} -c liste_ext.c

huffman.o: huffman.h arbre.h listes.h liste_ext.h
	${CC} ${CCOPTS} -c huffman.c

codage.o: codage.c codage.h
	clang -c codage.c

test.exe: main_codage.c caractere.o arbre.o codage.o
	clang main_codage.c caractere.o codage.o arbre.o -o test.exe

hoffman.exe: main_compression.c caractere.o arbre.o codage.o ecriture.o
	clang main_compression.c caractere.o arbre.o codage.o ecriture.o -o hoffman.exe

clean: 
	rm *.o