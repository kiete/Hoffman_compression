#include <stdlib.h>
#include <stdio.h>
#include "lecture.h"


char lecture(Bin_file * input){
    char bit;
    int ch;

    if (input->record_length == 0){
        while ((ch = getc(input->file)) != EOF){
            input->record[input->i_record] = ch;
            input->i_record += 1;
            input->record_length += 1;
        }
        input->i_record = 0;
        chartobin(input, input->record[input->i_record]);
        input->i_record += 1;
        input->i_octet = 0;
        input->nb_octets += input->record_length;     
    }

    bit = input->octet[input->i_octet];
    input->i_octet += 1;
    if (input->i_octet == 8){
        chartobin(input, input->record[input->i_record]);
        input->i_record += 1;
        input->i_octet = 0;
        if (input->i_record == BLOCK_SIZE){
            input->record_length = 0;
        }
    }
    
    return bit;
}

void chartobin(Bin_file * input, int c)
{
    int i;
    for(i = 7; i >= 0; i--){
        input->octet[i] = c % 2;      
        c = c / 2;          
    }
}

void open_file(Bin_file * input, char * name){
    input->file = fopen(name, "r+");
}

void close_file(Bin_file * input){
    fclose(input->file);
}

int main(int argc, char **argv)
{
    int bit;
    Bin_file * decodage = (Bin_file*)malloc(sizeof(Bin_file));
    if(argc < 2){
        printf("Usage : ./a.out <filename>\n");
        return 1;
    }

    open_file(decodage, argv[1]);
    decodage->i_record = 0;
    decodage->record_length = 0;
    for (int i = 0; i < 8; i++){
        bit = lecture(decodage);
        printf("%d\n", bit);
    }
    
    printf("%s\n", decodage->record);
    close_file(decodage);

    

    return 0;
}
