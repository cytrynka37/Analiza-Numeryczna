#include <iostream>
#include <cmath>
#include <iomanip>

double a(double x){
    double x5 = pow(x, 5);
    double x10 = pow(x, 10);
    double sqrt_term = sqrt(2024 + x10);
    return 1.0 / (x5 + sqrt_term);
}

double better_a(double x){
    double x5 = pow(x, 5);
    double x10 = pow(x, 10);
    double sqrt_term = sqrt(2024.0 + x10);
    if (x5 < 0) return (x5 - sqrt_term) / -2024.0;
    return 1.0 / (x5 + sqrt_term);
}

double b(double x){
    double ex = pow(M_Ef64, x);
    double ex2 = pow(M_Ef64, 2 * x);
    return 1e8 * (ex - ex2);
}

double better_b(double x){
    if (abs(x) < 10e-9){
        return 1e8 * -x;
    }
    return b(x);
}

double c(double x){
    double xm3 = pow(x, -3);
    double arcsx = asin(x) - x;
    return 6 * xm3 * arcsx;
}

double d(double x){
    double cos2x = cos(x) * cos(x);
    double c4 = 4 * cos2x;
    return c4 - 1;
}

double better_d(double x){
        return 2 * cos(2*x) + 1;
}

double better_d2(double x){
        return (2 * cos(x) + 1) * (2 * cos(x) - 1);
}


void runTests() {
    std::cout << std::fixed << std::setprecision(20);
    double testValues[] = {1e-9, 1e-12, 1e-15, 1e-17};

    std::cout << " x \t\t\t Standard \t\t\t Improved \t\n";
    std::cout << "---------------------------------------------------------------------------------------------------------\n";
    
    for (double x : testValues) {
        double standardResult = b(x);
        double improvedResult = better_b(x);


        std::cout << x << "\t" 
                  << standardResult << "\t" 
                  << improvedResult << "\t" 
                  <<  "\n";
    }
}

int main(){
    std::cout << "A: " << std::endl;
    std::cout << a(-100) << std::endl << better_a(-100) << std::endl;
    std::cout << a(100) << std::endl << better_a(100) << std::endl;

    std::cout << "B: " << std::endl;
    runTests();

    std::cout << "D: " << std::endl;
    for (double i = -20; i <= -1; i++){
        std::cout << d(M_PIf64/3 - pow(10, i)) << ", " << better_d(M_PIf64/3 - pow(10, i)) << std::endl;
    }
}