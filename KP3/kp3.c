#include <stdio.h>
#include <math.h>

const long double k = 10e2;
int MAX_ITER = 100;

long double machine_eps(long double x) {
    long double eps = 1.0l;
    while ((x + eps/2.0l) != x) {
        eps /= 2.0l;
    }
    return eps;
}

long double func(long double x) {
    return (2 * x - 3) / ((x - 1) * (x - 1));
}

long double form_teilor(long double x, int n){
    long double sum = 0;
    for (long double i = -(n + 3); i <= -3; i++){
        sum *= x;
        sum += i;
    }
    return sum;
}

int main() {
    long double b = 0.6, step, result;
    long double a = 0.1;
    int n;
    printf("Print the iterations: ");
    scanf("%Lf", &step);
    putchar('\n');
    printf("Taylor series values table for f(x) = (2x-3)/(x-1)^2\n");
    printf(" -----------------------------------------------------------------------------------\n");
    printf("|Machine epsilon| x \t| sum of line\t\t  | function\t\t    | iter |\n");
    printf(" ---------------|-------|-------------------------|-------------------------|-------\n");
    for (long double x = a; x <= b; x += (b - a) / step) {
        long double eps = machine_eps(x);
        for (n = 0; n < MAX_ITER; n++) {
            result = form_teilor(x, n);
            if (fabs(result) < eps*k) {
                break;
            }
        }
        if (fabs((int)result) >= 10) {
            printf("|%.8Le | %.3Lf\t| %.20Lf| %.20Lf|  %d |\n", eps, x, result, func(x), n);
        } else {
            printf("|%.8Le | %.3Lf\t| %.20Lf | %.20Lf |  %d |\n", eps,  x, result, func(x), n);
        }
        result = 0;
    }
    printf(" ----------------------------------------------------------------------------------\n");
    return 0;
}
