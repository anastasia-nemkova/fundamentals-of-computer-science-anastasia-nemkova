#ifndef PERSON_H
#define PERSON_H

#define LINE_SIZE (40U)

typedef struct{
    char surname[LINE_SIZE];
    char firstMiddle[LINE_SIZE];
    char gender;
    int group;
    int markMat;
    int markLA;
    int markDM;
    int markInf;
    int markEng;
    int markFil;
    int markEconom;
} Person;

void usage(){
    printf("Usage: program filename\nF");
}
#endif //_PERSON_H_