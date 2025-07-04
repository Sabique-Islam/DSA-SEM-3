#include <iostream>
using namespace std;

int main(){
    int n;
    int i = 2;
    int sum = 0;

    cout << "Enter the range -> ";
    cin >> n;

    while(i<=n){
        if (i%2 == 0){
            sum += i;
        }
        i++;
    }

    cout << "Sum of even number -> " << sum << endl;

    return 0;
}