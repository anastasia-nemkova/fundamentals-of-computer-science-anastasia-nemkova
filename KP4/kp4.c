#include <stdio.h>
#include <math.h>

double mashine_eps(double x) {
    double eps = 1.0;
    while (x + eps / 2.0 != x) {
        eps /= 2.0;
    }
    return eps;
}
    
double F1(double x) {
    return tan(x / 2) - (1 / tan(x / 2)) + x;
}

double F2(double x) {
    return 0.4 + atan(sqrt(x)) - x;
}

double exp_x1(double x) {
    return (1 / tan(x / 2)) - tan(x / 2);
}

double exp_x2(double x) {
    return 0.4 + atan(sqrt(x));
}

double derivative_F1(double x) {
    return (1 / (2 * pow(cos(x / 2), 2))) + (1 / (2 * pow(sin(x / 2), 2))) + 1;
}

double derivative_F2(double x) {
    return (1 / (2 * sqrt(x) + 2 * x * sqrt(x))) - 1;
}

double second_derivative_F1(double x) {
    return -(cos(x) / (2 * cos(x / 2) * pow(cos(x / 2), 2)) * sin(x / 2) * pow(sin(x / 2), 2));
}

double second_derivative_F2(double x) { 
    return -((1 + 3 * x) / (sqrt(x) * pow((2 * sqrt(x) + 2 * sqrt(x) * fabs(x)), 2)));
}

void dichot(double F(double), double a, double b) {
    double x = (a + b);
    double eps = mashine_eps(x);
    if (F(a) * F(b) <= 0) {
        while (fabs(a - b) > eps) {
            x = (a + b) / 2;
            if (F(x) * F(a) < 0) {
                b = x;
            } else {
                a = x;
            }
        }
        printf("The root obtained by the dichotomy method:%11.7f\n", x);       
    } else {
        printf("The dichotomy method is not applicable \n");
    }
}

void itter(double exp_x(double), double a, double b) {
    double x = (a + b) / 2;
    double eps = mashine_eps(x);
    if (exp_x(x) >= 1) {
        while (fabs(exp_x(x) - x) > eps) {
            x = exp_x(x);  
        }
        printf("The root obtained by iteration method:%11.7f\n", x);
    } else {
        printf("The iteration method is not applicable \n");
    }
}

void newton(double F(double), double derivative_F(double), double second_derivative_F(double), double a, double b) {
    double x = a + b / 2;
    double eps = mashine_eps(x);
    if (fabs(F(x) * second_derivative_F(x)) < pow(derivative_F(x), 2)) {
        while (fabs(F(x) / derivative_F(x)) > eps) {
            x -= F(x) / derivative_F(x);
        }
        printf("The root obtained by Newton's method:%11.7f\n", x);
    } else {
        printf("Newton's method is not applicable \n");
    }  
}

void result(double F(double), double derivative_F(double),  double second_derivative_F(double), double exp_x(double), double a, double b){
    dichot(F, a, b);
    itter(exp_x, a, b);
    newton(F, derivative_F, second_derivative_F, a, b);
}

int main() {
    double a = 1;
    double b = 2;
    printf("Function tan(x / 2) - ctg(x / 2) + x \n");
    result(F1, derivative_F1, second_derivative_F1, exp_x1, a, b);
    printf("Function 0.4 + atan(sqrt(x)) - x\n");
    result(F2, derivative_F2, second_derivative_F2, exp_x2, a, b);
    return 0;
}

