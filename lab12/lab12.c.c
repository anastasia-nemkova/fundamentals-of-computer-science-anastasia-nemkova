#include <stdio.h>

int main() {
    long N;
    scanf_s("%ld", &N);
    int d, k;
    int c = 0;
    k = N % 10;
    while (N != 0) {
        N = N / 10;
        d = N % 10;
        if (d == k) {
            c = 1;
            break;
        }
        k = d;
    }
    if (c) printf("NO\n");
    else printf("DIFFERENT\n");
    return 0;
}
