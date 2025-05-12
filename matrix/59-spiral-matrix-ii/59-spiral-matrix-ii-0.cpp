int d[5] = {0 , 1 , 0 , -1 , 0};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n , vector<int>(n , -1));
        int x = 0 , y = 0;
        int dir = 0;
        int fill = 1;
        for(int i = 0 ; i < n*n ; ++i){
            ans[x][y] = fill;
            x += d[dir];
            y += d[dir + 1];
            if(min(x , y) < 0 || x >= n || y >= n || ans[x][y] > 0){
                x -= d[dir];
                y -= d[dir + 1];
                dir = (dir + 1)%4;
                x += d[dir];
                y += d[dir + 1];
            }
            ++fill;
        }
        return ans;
    }
};