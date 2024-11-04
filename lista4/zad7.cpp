#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

double newtonSqrt(double a, double x0, double tolerance = 1e-10, int maxIterations = 1000) {
    double x = x0;
    for (int i = 0; i < maxIterations; ++i) {
        double x_next = 0.5 * (x + a / x); // Ulepszona formuła Newtona
        if (fabs(x_next - x) < tolerance) {
            return x_next; // Zbieżność
        }
        x = x_next;
    }
    return x; // Zwraca ostatnią wartość, jeśli nie osiągnięto zbieżności
}

double calculateA(double m, int c) {
    return m * pow(2, c); // Oblicza a = m * 2^c
}

void runTests() {
    std::vector<std::pair<double, int>> testCases = {
        {0.5, 0},   // a = 0.5 * 2^0 = 0.5
        {0.75, 1},  // a = 0.75 * 2^1 = 1.5
        {0.9, 2},   // a = 0.9 * 2^2 = 3.6
        {0.6, 3},   // a = 0.6 * 2^3 = 4.8
        {0.25, 4},  // a = 0.25 * 2^4 = 4
        {0.1, 5},   // a = 0.1 * 2^5 = 3.2
        {0.95, 6},  // a = 0.95 * 2^6 = 60.8
        {0.33, 2},  // a = 0.33 * 2^2 = 1.32
        {0.125, 1}, // a = 0.125 * 2^1 = 0.25
        {0.5, 5}    // a = 0.5 * 2^5 = 16
    };

    std::cout << std::fixed << std::setprecision(10);
    for (const auto& testCase : testCases) {
        double m = testCase.first;
        int c = testCase.second;
        double a = calculateA(m, c);
        double expectedSqrt = sqrt(a);
        double computedSqrt = newtonSqrt(a, 0.000000000001); // Użycie a/2 jako x0

        std::cout << "Test case: m = " << m << ", c = " << c << " => a = " << a
                  << "\nExpected sqrt(a) = " << expectedSqrt
                  << "\nComputed sqrt(a) = " << computedSqrt
                  << "\nDifference = " << fabs(computedSqrt - expectedSqrt) << "\n\n";
    }
}

int main() {
    runTests();
    return 0;
}
