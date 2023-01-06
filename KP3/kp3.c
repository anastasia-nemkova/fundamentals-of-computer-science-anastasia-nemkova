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

long double func(long double x) {
    return (2 * x - 3) / ((x - 1) * (x - 1));
}

long double form_teilor(long double x, int n){
    long double sum = 0;
    for (long double i = -(n + 3); i <= -3; i++){
        sum = sum * x + i;
    }
    return sum;
}

int main() {
    long double eps = machine_eps();
    long double b = 0.6, step, result;
    int n;
    long double a = 0.1;
    printf("Print the iterations: ");
    scanf("%d", &n);
    putchar('\n');
    step = (b - a) / n;
    printf("Machine epsilon for long double = %.20Lf\n", eps);
    printf("Taylor series values table for f(x) = (2x-3)/(x-1)^2\n");
    printf(" -------------------------------------------------------------------\n");
    printf("| x \t| sum of line\t\t  | function\t\t    | iter |\n");
    printf(" -------|-------------------------|-------------------------|-------\n");
    for (long double x = a; x <= b; x += step) {
        for (n = 0; n < MAX_ITER; n++) { 
            result = form_teilor(x, n);
            if (fabs(result) < eps*k) {
                break;
            }
        }
        if (fabs((int)result) >= 10) {
            printf("| %.3Lf\t| %.20Lf| %.20Lf|  %d |\n", x, result, func(x), n);
        } else {
            printf("| %.3Lf\t| %.20Lf | %.20Lf |  %d |\n", x, result, func(x), n);
        }
        result = 0;
    }
    printf(" -------------------------------------------------------------------\n");
    return 0;
}
