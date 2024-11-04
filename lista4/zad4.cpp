#include <iostream>
#include <math.h>
#include <iomanip>

const double EPSILON = 1e-6;

double f(double x) {
    return x * x - std::atan(x + 2);
}

double bisection(double a, double b) {
    double m = 0;
    while (abs((b - a) / 2.0) > EPSILON) {
        m = (a + b) / 2.0;
        if (f(m) == 0.0) return m;
        else if (f(m) * f(a) < 0) b = m;
        else a = m;
    }
    return m;
}

int main() {
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Miejsce zerowe w przedziale [-2, 0]: x = " << bisection(-2, 0) << std::endl;
    std::cout << "Miejsce zerowe w przedziale [0, 2]: x = " << bisection(0, 2) << std::endl;
}
