#include <stdio.h>
#include <math.h>

double mashine_eps() {
    double eps = 1.0;
    while (1 + eps / 2.0 != 1) {
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

double derivative_fx1(double x) {
    return -2 * (1 / pow(sin(x), 2));
}

double derivative_fx2(double x) {
    return 1 / (2 * sqrt(x) + 2 * x * sqrt(x));
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

double dichot(double (*F)(double), double a, double b, double abs_eps, double otn_eps) {
    double x = (a + b);
    if (F(a) * F(b) <= 0) {
        while (fabs(a - b) > fmax(otn_eps * fmax(fabs(a), fabs(b)), abs_eps)) {
            x = (a + b) / 2;
            if (F(x) * F(a) < 0) {
                b = x;
            } else {
                a = x;
            }
        }
        return x;;       
    } else {
        return 0;
    }
}

double itter(double (*derivative_fx)(double), double (*exp_x)(double), double a, double b, double abs_eps, double otn_eps) {
    double x = (a + b) / 2;
    if (fabs(derivative_fx(x)) < 1) {
        while (fabs(exp_x(x) - x) >= fmax(otn_eps * fmax(fabs(exp_x(x)), fabs(x)), abs_eps)) {
            x = exp_x(x);  
        }
        return x;
    } else {
        return 0;
    }
}
double newton(double (*F)(double), double (*derivative_F)(double), double (*second_derivative_F)(double), double a, double b, double abs_eps, double otn_eps) {
    double x = a + b / 2;
    if (fabs(F(x) * second_derivative_F(x)) < pow(derivative_F(x), 2)) {
        while (fabs(F(x) / derivative_F(x)) > fmax(otn_eps *  fabs(F(x) / derivative_F(x)), abs_eps) ) {
            x -= F(x) / derivative_F(x);
        }
        return x;
    } else {
        return 0;
    }  
}

void result(double (*F)(double), double (*derivative_fx)(double), double (*derivative_F)(double),  double (*second_derivative_F)(double), double (*exp_x)(double), double a, double b, double abs_eps, double otn_eps){
    double d = dichot(F, a, b, abs_eps, otn_eps);
    double i = itter(derivative_fx, exp_x, a, b, abs_eps, otn_eps);
    double n = newton(F, derivative_F, second_derivative_F, a, b, abs_eps, otn_eps);
    if (d != 0) {
        printf("The root obtained by the dichotomy method:%11.7f\n", d);
    } else {
        printf("The dichotomy method is not applicable \n");
    }
    if (i != 0) {
        printf("The root obtained by iteration method:%11.7f\n", i);
    } else {
        printf("The iteration method is not applicable \n");
    }
    if (n != 0) {
        printf("The root obtained by Newton's method:%11.7f\n", n);
    } else {
        printf("Newton's method is not applicable \n");
    }
}

int main() {
    double a = 1;
    double b = 2;
    double abs_eps = mashine_eps();
    double otn_eps = sqrt(abs_eps);
    printf("Function tan(x / 2) - ctg(x / 2) + x \n");
    result(F1, derivative_fx1, derivative_F1, second_derivative_F1, exp_x1, a, b, abs_eps, otn_eps);
    printf("Function 0.4 + atan(sqrt(x)) - x\n");
    result(F2, derivative_fx2, derivative_F2, second_derivative_F2, exp_x2, a, b, abs_eps, otn_eps);
    return 0;
}

