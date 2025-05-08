int d[5] = {-1 , 0 , 1 , 0 , -1};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<int>dist(n*m , 2e9);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        dist[0] = 0;
        pq.emplace(0,0,0);
        while(!pq.empty()){
            auto [cost , src , prt] = pq.top();
            pq.pop();
            if(src == n*m - 1) return cost;
            if(dist[src] < cost) continue;
            int x = src/m , y = src%m;
            for(int i = 0 ; i < 4 ; ++i){
                int X = x + d[i] , Y = y + d[i + 1];
                if(min(X , Y) >= 0 and X < n and Y < m){
                    int ncost = max(cost , grid[X][Y]) + (prt + 1);
                    int nsrc = X*m + Y;
                    if(dist[nsrc] > ncost){
                        dist[nsrc] = ncost;
                        pq.emplace(ncost , nsrc , prt^1);
                    }
                }
            }
        }
        return -1;
    }
};