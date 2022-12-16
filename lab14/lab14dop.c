#include <stdio.h>
#define N (7)

void matrix_diag(size_t n, int (*matrix)[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = (n - 1); j >= 0; j--) {
            if (i != j && (i + j) == (n - 1)) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
}

void matrix_triangle(size_t n, int (*matrix)[n]) {
    for (int j = 1; j < n; j++) {
        for (int i = (n - 2); i < n; i--) {
            if (j > i && (i + j) >= n) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < (n - 1); j++) {
            if (i > j && (i + j) >= n) {
                 printf("%d ", matrix[i][j]);
            }
        }
    }
    for (int j = 2; j < n; j--) {
        for (int i = 1; i < (n - 1); i++) {
            if (i > j && (i + j) < (n - 1)) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    for (int i = 2; i < n; i--) {
        for (int j = (n - 1); j < n; j--) {
            if ( j > i && (i + j) < (n - 1)) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}
 
int main() {
    size_t n;
    scanf("%zu", &n);
    int matrix[N * N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i * n + j]);
        }
    }
    if (n == 1) {
        printf("%d\n", matrix[0 * 0]);
    } else {
        matrix_diag(n, (int (*)[n]) matrix);
        matrix_triangle(n, (int (*)[n]) matrix);
        return 0;
    }
}
        
