int d[5] = {0 , 1 , 0 , -1 , 0};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0 , y = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int dir = 0;
        for(int i = 0 ; i < n*m ; ++i){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = 101;
            x += d[dir];
            y += d[dir + 1];
            if(min(x , y) < 0 || x >= n || y >= m || matrix[x][y] == 101){
                x -= d[dir];
                y -= d[dir + 1];
                dir = (dir + 1)%4;
                x += d[dir];
                y += d[dir + 1];
            }
        }
        return ans;
    }
};