#include <vector>
using namespace std;

class Solution {
public:

    vector<int> generateRow(int row){
        long long ans = 1;
        vector <int> ansRow;
        ansRow.push_back(1);
        for(int col=1; col<row; col++){
            ans = ans *(row-col);
            ans = ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int rows) {
        vector<vector<int>> result;
        for(int i=1; i<=rows; i++){
            result.push_back(generateRow(i));
        }
        return result;
    }
};