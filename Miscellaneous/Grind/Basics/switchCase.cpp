#include <iostream>

using namespace std;

int main(){

    int num = 1;

    while(1){
        switch(num){
            case 1:
                cout << "1" << endl;
                break;
            case 2:
                cout << "2" << endl;
                break;
            default:
                cout << "Hey!" << endl;
        }
        exit(0); // Exits entire program
    }
    cout << "Out of infinite loop ..." << endl;
    return 0;
}