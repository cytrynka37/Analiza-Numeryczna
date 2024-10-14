#include <bits/stdc++.h>
using namespace std;
#define precision double


precision calc_pi(int n){
    precision pi = 0;
    for(int k = 0; k < n; k++){
        if(k%2) pi -= 1./(precision)(2*k+1);
        else pi += 1./(precision)(2*k+1);
    }

    return 4.*pi;
}


int main(){
    double num = 2e6;
    cout << setprecision(9) << calc_pi(num) << '\n';
    cout << M_PI << '\n';
}