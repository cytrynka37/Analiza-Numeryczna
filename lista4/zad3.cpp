#include <iostream>
#include <math.h>
#include <iomanip>

double f(double x) {
    return x - 0.49;
}

int main() {
    double a0 = 0;
    double b0 = 1;

    double a = a0;
    double b = b0;

    for (int n = 0; n <= 5; n++) {
        double midpoint = (a + b) / 2.0;
        double real_error = std::abs(0.49 - midpoint);
        double en = (b0 - a0) / std::pow(2, (n + 1));
        double diff = en - real_error;
        
        std::cout << n << " | a: " << a << " | b: " << b << " | mp: " << midpoint 
                  << " | błąd: " << real_error << " | oszacowanie: " << en << " | różnica: " << diff << std::endl;

        if(f(midpoint) > 0) b = midpoint;
        else a = midpoint;
    }
}
