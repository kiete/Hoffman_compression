CC = clang
CCOPTS = -Wall

all: hoffman.exe test.exe

ecriture.o: ecriture.c ecriture.h
	clang -c ecriture.c

arbre.o: arbre.c arbre.h
	clang -c arbre.c

liste_ext.o: liste_ext.c liste_ext.h listes.h
	${CC} ${CCOPTS} -c liste_ext.c

huffman.o: huffman.h arbre.h listes.h liste_ext.h
	${CC} ${CCOPTS} -c huffman.c arbre.c liste_ext.c

codage.o: codage.c codage.h
	clang -c codage.c

test.exe: main_codage.c  arbre.o codage.o
	clang main_codage.c  codage.o arbre.o -o test.exe

hoffman.exe: main_compression.c  arbre.o codage.o ecriture.o huffman.o lecture.o liste_ext.o
	clang main_compression.c  arbre.o codage.o ecriture.o huffman.o lecture.o liste_ext.o -o huffman.exe

clean: 
	rm *.o