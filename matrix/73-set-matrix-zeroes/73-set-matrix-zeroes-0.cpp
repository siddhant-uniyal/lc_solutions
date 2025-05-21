int d[5] = {-1 , 0 , 1 , 0 , -1};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = n - 1 ; i >= 0 ; --i){
            for(int j = m - 1 ; j >= 0 ; --j){
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
    }
};