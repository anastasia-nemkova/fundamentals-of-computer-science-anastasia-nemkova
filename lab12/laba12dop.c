#include <stdio.h>

typedef enum {
    LIMITATIONS,
    NUMBER1,
    NUMBER2,
    COMPARISON,
    ENTER,
}Step;


int process() {
    int d, k;
    int c = 0;
    int g = 0;
    Step step = LIMITATIONS;
    char N = getchar();
    while (N != EOF) {
        switch(step) {
            case LIMITATIONS:
                if(N != ' ') {
                    step = NUMBER1;
                }
                if(N == '\n') {
                    break;
                }
                if(N == ' ') {
                    step = ENTER;
                    continue;  
                }
            case NUMBER1:
                d = N - '0';
                step = NUMBER2;
            case NUMBER2:
                N = getchar();
                if (N != ' ') {
                    k = N - '0';
                step = COMPARISON;
                }
                if(N == ' ') {
                    step = ENTER;
                    continue;
                }
            case COMPARISON:
                if(d == k) {
                    ++g;
                }
                step = LIMITATIONS;       
                continue;
            case ENTER:
              goto newword;
          }
          
        newword: break;
        
    }
    return g;
       
}

void result() {
    for (char N = getchar(); N != EOF; N = getchar()) {
        if(N!= ' ') {
            int g = process();
            if(g > 0) {
                printf("NO\n");
            }
            if(g == 0) {
                printf("DIFFERENT\n");
            }
        }
    }        
}
 
 int main() {
     result();
     return 0;
 }
