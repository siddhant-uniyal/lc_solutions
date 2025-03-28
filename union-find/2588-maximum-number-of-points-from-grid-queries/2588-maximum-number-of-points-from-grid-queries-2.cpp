int d[5] = {-1 , 0 , 1 , 0 , -1};
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        /*
        sort queries , append to prev answer.
        how to expand previous answer?
        tried expansion with bfs : bfs queue holds all cells from previous queries
        do bfs from these cells , try expanding
        TLE , since at max n*m nodes in bfs queue
        tried optimizing : if a cell has all neighbours visited , remove from bfs queue , since it cant expand further , expansion will be done by neighbours
        WA : idk why
        need for optimization : didnt know when to pop or not
        have to pop the current cell
        */
        int k = queries.size();
        vector<int>ids(k);
        iota(ids.begin() , ids.end() , 0);
        sort(ids.begin() , ids.end() , [&](const int &a , const int &b){
            return queries[a] < queries[b];
        });
        vector<int>ans(k);
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>vis(n*m);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>bfs;
        bfs.emplace(grid[0][0] , 0);
        vis[0] = 1;
        for(int i = 0 ; i < k ; ++i){
            int lim = queries[ids[i]];
            while(!bfs.empty() and bfs.top().first < lim){
                ++cnt;
                auto [ _ , src] = bfs.top();
                bfs.pop();
                int x = src/m , y = src%m;
                for(int j = 0 ; j < 4 ; ++j){
                    int X = x + d[j] , Y = y + d[j + 1];
                    if(min(X , Y) >= 0 and X < n and Y < m and !vis[X*m + Y]){
                        bfs.emplace(grid[X][Y] , X*m + Y);
                        vis[X*m + Y] = 1;
                    }
                }
            }
            ans[ids[i]] = cnt;
        }
        return ans;
    }
};
//append : 12:50am , 1