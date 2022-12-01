#include <stdio.h>

typedef enum {
    READING,
    FIRST_LIMITATION,
    SECOND,
    TRANSLATION,
    HASHING,
    ENTER,
}Step;

Step step = READING;
     
void hash_f() {
    int hash = 0;
    int sim;
    long p = 1;
    const int mod = 1e9 + 7, k = 31;
    for(char word = getchar(); word != EOF ; word = getchar()) {
        switch(step) {
            case READING:
                if(word != ' ') {
                    step = ENTER;
                }
                if(word == ' ') {
                    goto stop;
                    break;
                }
            case ENTER:
                if(word == '\n') {
                    printf("hash is %d\n", hash);
                    break;
                }
                if(word != '\n') {
                    step = FIRST_LIMITATION;     
                }
            case FIRST_LIMITATION:
                if(word == '!' || word == '.' || word == '\t' || word == '\r') {
                    step = TRANSLATION;
                }    
            case TRANSLATION:
                sim = word;
                step = HASHING;
                printf("%d\n", sim);
            case HASHING:
                hash = (hash + sim * p) % mod;
                p = (p * k) % mod;
                step = READING;
                continue;

                
        }
    stop: printf("hash is %d\n", hash); continue;   
    }
    
}
                 
int main(){
    hash_f();
    return 0;
}
