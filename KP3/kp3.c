#include <stdio.h>
#include <math.h>

const long double k = 10e2;
int MAX_ITER = 100;

long double machine_eps() {
    long double eps = 1.0;
    while ((1.0 + eps) > 1.0) {
        eps *= 0.5;
    }
    return eps;
}

long double Abs(long double a) {
    return a >= 0 ? a : -a;
}

long double func(long double x) {
    return (2 * x - 3) / ((x - 1) * (x - 1));
}

long double Pow(long double x, long double n, long double i) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else if (n > 1) {
        return x * i;
    }
    return 0;
}
long double teilor_member(long double x,  int n, long double i){
    long double sum = -(n + 3) * Pow(x, n, i);
    return sum;
}

int main() {
    long double eps = machine_eps();
    long double b = 0.6, step, iter, result, cur_number, x;
    long double a = 0.1;
    int count = 0;
    printf("Print the iterations: ");
    scanf("%Lf", &iter);
    putchar('\n');
    step = (b - a) / iter;
    printf("Machine epsilon for long double = %.20Lf\n", eps);
    printf("Taylor series values table for f(x) = (2x-3)/(x-1)^2\n");
    printf(" -------------------------------------------------------------------\n");
    printf("| x \t| sum of line\t\t  | function\t\t    | iter |\n");
    printf(" -------|-------------------------|-------------------------|-------\n");
    for (long double i = a; i <= b; i += step) {
        x = i;
        for (int n = 0; n <= MAX_ITER ; n++) {
            cur_number = teilor_member(x, n, i);
            result += cur_number;
            count ++;
            if (n > 1) {
                x *= i;
            }
            if (Abs(cur_number) < eps*k) {
                break;
            }
        }
        if (Abs((int)result) >= 10) {
            printf("| %.3Lf\t| %.20Lf| %.20Lf|  %d  |\n", i, result, func(i), count);
        } else {
            printf("| %.3Lf\t| %.20Lf | %.20Lf |  %d  |\n", i, result, func(i), count);
        }
        result = 0;
        count = 0;
    }
    printf(" -------------------------------------------------------------------\n");
    return 0;
}
