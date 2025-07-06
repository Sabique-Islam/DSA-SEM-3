#include <iostream>

using namespace std;

int fact(int n){
    int f = 1;
    for(int i=1; i<=n; i++){
        f *= i;
    }
    return f;
}

int nCr(int n, int r){
    if(n < r){
        return 0;
    }
    return fact(n)/(fact(r)*fact(n-r));
}

int main(){

    cout << "nCr = " << nCr(5,2) << endl;

    return 0;
}