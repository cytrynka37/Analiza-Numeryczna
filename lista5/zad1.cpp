#include <iostream>
#include <math.h>

const double eCH[4] = {0.763907023, 0.543852762, 0.196247370, 0.009220859};
const double eA[4] = {0.605426053, 0.055322784, 0.004819076, 0.000399783};

double rate_of_conv(double ep, double e, double en){
    return log(abs(en / e)) / log(abs(e / ep));
}

double number_of_steps(double e0, double e1, double conv, double emax = 1e-100){
    int n = 1;
    double lep = log(abs(e0));
    double le = log(abs(e1));
    while(le > log(abs(emax))){
        n++;
        double len = conv * (le - lep) + le;
        lep = le;
        le = len;
    }
    return n;
}

int main(){
    double rate_russia = rate_of_conv(eCH[0], eCH[1], eCH[2]);
    double rate_america = rate_of_conv(eA[0], eA[1], eA[2]);

    std::cout << "wykladnik zbieznosci:\n";
    std::cout << "Chiny: " << rate_russia << std::endl;
    std::cout << "Ameryka: " << rate_america << std::endl;

    std::cout << "\nliczba tygodni: \n";
    std::cout << "Chiny: " << number_of_steps(eCH[0], eCH[1], rate_russia) << std::endl;
    std::cout << "Ameryka: " << number_of_steps(eA[0], eA[1], rate_america) << std::endl;
}
