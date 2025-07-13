#include <iostream>
using namespace std;

long long int binarySearch(int num){
    int start = 0;
    int end = num;
    long long int mid = start + (end - start)/2;

    long long int ans = -1;

    while(start <= end){
        long long int square = mid*mid;

        if(square == num){
            return mid;
        }
        if(square < num){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

double morePrecision(int num, int precision, int sol){
    double factor = 1;
    double ans = sol;
    for(int i = 0; i < precision; i++){
        factor /= 10;
        for(double j = ans; j*j < num; j = j + factor){
            ans = j;
        }
    }
    return ans;
}

int mySqrt(int x){
    if(x < 0) return -1;
    return binarySearch(x);
}

int main(){

    int x = 5;
    cout << "Square root of " << x << " is " << mySqrt(x) << endl;
    int precision = 3;
    int sol = mySqrt(x);
    cout << "Square root of " << x << " with precision " << precision << " is " << morePrecision(x, precision, sol) << endl;
    return 0;
}