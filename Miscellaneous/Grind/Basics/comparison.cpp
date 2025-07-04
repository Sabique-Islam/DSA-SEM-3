#include <iostream>
using namespace std;

int main(){
    int a = 2;
    int b = a + 1;  // b = 3

    if ((a = 3) == b) {
        cout << a; // 3
    }
    else {
        cout << a + 1;
    }
    return 0;
}