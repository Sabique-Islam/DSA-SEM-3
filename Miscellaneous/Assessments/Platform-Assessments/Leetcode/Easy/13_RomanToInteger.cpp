#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int getNum(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }

    int romanToInt(string s) {
        int size = s.length();
        int result = 0;
        for(int i=0; i<size; i++){
            int current = getNum(s[i]);
            int next = getNum(s[i+1]);

            if (current < next){
                result -= current;
            }else{
                result += current;
            }
        }

        return result;
    }
};