#include <stdio.h>
#include <math.h>

const long double k = 10e9;
int MAX_ITER = 100;

double machine_eps() {
    double eps = 1.0;
    while ((1 + eps/2.0) != 1) {
        eps /= 2.0;
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
    double abs_eps = machine_eps();
    double otn_eps = sqrt(abs_eps);
    printf("Print the iterations: ");
    scanf("%Lf", &step);
    
    putchar('\n');
    
    printf("Machine epsilon for double type  = %.16e\n", abs_eps);
    
    printf("Taylor series values table for f(x) = (2x-3)/(x-1)^2\n");
    printf(" -------------------------------------------------------------------------\n");
    printf("| x \t| sum of line\t\t  | function\t\t    | iter\t |\n");
    printf(" -------|-------------------------|-------------------------|-------------\n");
    for (long double x = a; x <= b; x += (b - a) / step) {
        for (n = 0; n < MAX_ITER; n++) {
            result = form_teilor(x, n);
            if (fabs(result) <= fmax(otn_eps * fabs(result), abs_eps)) {
                break;
            }
        }
        if (fabs((int)result) >= 10) {
            printf("| %.3Lf\t| %.20Lf| %.20Lf|  %d\t |\n",  x, result, func(x), n);
        } else {
            printf("| %.3Lf\t| %.20Lf | %.20Lf |  %d\t |\n", x, result, func(x), n);
        }
        result = 0;
    }
    printf(" -------------------------------------------------------------------------\n");
    return 0;
}
