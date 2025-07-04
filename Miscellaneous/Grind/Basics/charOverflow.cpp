#include <iostream>
using namespace std;

int main(){
    char a = 97;
    //cout << a << endl;

    char b = 123456;
    cout << b << endl;

    cout << static_cast<char>(123456 & 0xFF) << endl; // 0x -> hexadecimal

}