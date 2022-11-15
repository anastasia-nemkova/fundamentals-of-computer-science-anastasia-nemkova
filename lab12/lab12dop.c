#include <stdio.h>
#include <stdlib.h>

void process() {
    char N;
    int d, k, num;
    int c = 0;
    int g = 0;
    N = getchar();
    while( N != EOF || N == 0){  
        if( N != ' ' && N != '\n' ){     
            num = N - 48;
            if(num || num == 0){
                d = num;    
                N = getchar();
                k = N - 48;
            //printf("%d\n %d\n", num,k);
                if ( k == d){
                    g = g + 1;
                    continue;
                    }else{
                        c = c + 1;
                        continue;
                    }
            } 
        }else if( N == ' '){
            process();
        }
    if (c > 0 && g == 0){ 
        printf("DIFFERENT\n");
        break;
    }if(g > 0) {
         printf("NO\n");
         break;
    }
     
    } 
} 
 
 int main(){
     process();
     return 0;
 }

