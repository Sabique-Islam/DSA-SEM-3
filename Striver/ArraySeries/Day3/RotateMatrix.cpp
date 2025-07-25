#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // row = col

        int row = matrix.size();
        int col = matrix[0].size();

        // int left = 0;
        // int right = row-1;

        // int top = 0;
        // int bottom = col-1;

        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                if(i!=j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(int i=0; i<row; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};