int d[5] = {-1 , 0 , 1 , 0 , -1};
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        auto dfs = [&](int src , auto &&self) -> int{
            int x = src/m , y = src%m;
            int to_return = 0;
            int og = grid[x][y];
            grid[x][y] = 0;
            for(int i = 0 ; i < 4 ; ++i){
                int X = x + d[i] , Y = y + d[i + 1];
                if(min(X,Y) >= 0 and X < n and Y < m and grid[X][Y]){
                    to_return = max(to_return , self(X*m + Y , self));
                }
            }
            grid[x][y] = og; 
            return to_return + og;
        };
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!grid[i][j]) continue;
                ans = max(dfs(i*m + j , dfs) , ans);
            }
        }
        return ans;
    }
};