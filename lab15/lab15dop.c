/* conc(a, b) = a * 10^(len(b)) + b
   a * b + a + b = a * 10^(len(b)) + b
   b = 10^(len(b)) - 1, т.е. при b = 9,99,...,99...9 равенство верное
   т.о. ответом будет кол-во чисел типа b в диапозоне от 1 до B, умноженное на a
*/
#include <stdio.h>
        
int length(long long num) {
    int rslt_num = 0;
    int len = 0;
    while(num != 0) {
        rslt_num += num % 10;
        num /= 10;
        ++len;
    }
    if(rslt_num / 9 == len) {
        return len;
    } else {
        return len - 1;
    }
}

void counting_pairs() {
    int t;
    scanf("%d\n", &t);
    for(int i = 0; i < t; ++i){
        long long a,b;
        long long num_pairs = 0;
        scanf("%lld %lld", &a, &b);
        num_pairs = a * length(b);
        printf("%lld\n", num_pairs);
    }
}

int main() {
    counting_pairs();
    return 0;
}
     
