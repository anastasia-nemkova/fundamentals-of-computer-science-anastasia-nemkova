#include <stdio.h>
#define N (8)

int min(int n, int (*matrix)[n]) {
    int min_elem;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((i == 1 && j == 0) || matrix[i][j] < min_elem) {
                min_elem = matrix[i][j];
            }
        }
    }
    return min_elem;
}

void multiplication_elem(int n, int (*matrix)[n], int min_elem) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            matrix[i][j] = matrix[i][j] * min_elem;
        }
    }
} 

int main() {
    int n;
    scanf("%d", &n);
    int matrix[N * N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i * n + j]);
        }
    }
    int min_elem = min(n, (int (*)[n]) matrix);
    printf("Min elem: %d\n", min_elem);
    multiplication_elem(n, (int (*)[n]) matrix, min_elem);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }
    return 0;
}
