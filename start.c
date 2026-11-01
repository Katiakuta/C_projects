#include <stdio.h>
#include <math.h>

double a(double x) {
    return x;
}

double Integral(double (*f)(double x), double from , double to, double step) {
    double sum = (f(from) + f(to))/2;
    for (double x = from+step; x < to - step; x += step) {
        sum += f(x);
    }
    return sum*step;
}

int main() {
    printf("Integral = %lf\n", Integral(a, 0, 1, 0.1));
    return 0;
}