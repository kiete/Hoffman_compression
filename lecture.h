#ifndef LECTURE_H
#define LECTURE_H

#include <stdlib.h>
#include <stdio.h>
#define BLOCK_SIZE 4096

typedef struct {
    FILE * file;
    char mode;
    unsigned char record [BLOCK_SIZE];
    int record_length;
    int i_record;
    char octet[8];
    int i_octet;
    int nb_octets;
} Bin_file;

void close_file(Bin_file * input);
void open_file(Bin_file * input, char * name);
char lecture(Bin_file * input);
void chartobin(Bin_file * input, int c);

#endif