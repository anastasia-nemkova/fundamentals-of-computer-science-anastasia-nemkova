#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "person.h"

int readPerson(FILE *in, Person * const person){
    return fscanf(in, "%s\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", person -> surname, person -> firstMiddle, &person -> gender, &person -> group, &person -> markMat, &person -> markLA, &person -> markDM, &person -> markInf, &person -> markEng, &person -> markFil, &person -> markEconom) == 11;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        usage();
        return 1;
    }
    Person person;
    FILE *in = fopen(argv[2], "r");
    if(!in){
        perror("Can't open file\n");
        return 2;
    }
    FILE *out = fopen(argv[1], "w");
    if(!out){
        perror("Can't open file\n");
        return 2;
    }
    
    while(readPerson(in, &person)){
        fwrite(&person, sizeof(person), 1, out); 
    }
    fclose(in);
    fclose(out);
    return 0;
}