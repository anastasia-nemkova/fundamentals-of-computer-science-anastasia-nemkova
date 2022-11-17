#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void processing_string() {
    int sym = 0;
    int sim;
    int sim1;
    char word;
    word = getchar();
    while(word != EOF){
        if(word != ' ' && word != '\t' || word == '!' || word == '.'){
            sim = word;
            word = getchar();
            if(word != ' '){
                sim1 = word;
                if(sim && sim1!=10){
                    sym = sym + sim*sim1 + sim/sim1;
                    continue;
                }
        
            }else if(word == ' '){
                processing_string();
            }
            printf("%d\n", sym); 
            break;

        }else if(word == ' '){
            processing_string();
        }
    }
}

int main() {
  processing_string(); 
  return 0;
}
