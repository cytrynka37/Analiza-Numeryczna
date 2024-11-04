#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <iomanip>

std::pair<double, int> inverseSqrtNewton(double a, double x0, double tolerance = 1e-10, int max_iterations = 100) {
    double x = x0;
    int iterations = 0;

    for (int i = 0; i < max_iterations; ++i) {
        double x_next = x * (1.5 - 0.5 * a * x * x);
        if (std::abs(x_next - x) < tolerance) {
            return {std::abs(x_next), iterations + 1};
        }
        x = x_next;
        iterations++;
    }
    return {std::numeric_limits<double>::infinity(), iterations};
}

void testInverseSqrt() {
    std::vector<double> test_values = {2.0, 4.0, 16.0, 20.0, 25.0};
    std::vector<double> initial_guesses = {0.01, 0.1, 0.25, 0.3, 0.4, 0.43, 0.5, 0.7, 1.0, 2.0};

    std::cout << std::setprecision(15);
    for (double a : test_values) {
        for (double x0 : initial_guesses) {
            auto [result, iterations] = inverseSqrtNewton(a, x0);
            if (result != std::numeric_limits<double>::infinity()) {
                std::cout << "Dla a = " << a << " i x0 = " << x0
                          << ", odwrotność pierwiastka kwadratowego to: " << result
                          << " (liczba iteracji: " << iterations << ")" << std::endl;
            } else {
                std::cout << "Dla a = " << a << " i x0 = " << x0
                          << " nie osiągnięto zbieżności." << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    testInverseSqrt();
    return 0;
}
