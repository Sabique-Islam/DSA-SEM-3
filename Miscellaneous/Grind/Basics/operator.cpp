#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int b = 10;

    cout << "a&b = " << (a&b) << endl; // AND
    cout << "a|b = " << (a|b) << endl; // OR
    cout << "a^b = " << (a^b) << endl; // XOR
    cout << "~a = " << (~a) << endl; // NOT
    cout << "~b = " << (~b) << endl; // NOT
    cout << "a<<1 = " << (a<<1) << endl; // Left Shift
    cout << "b>>1 = " << (b>>1) << endl; // Right Shift
}