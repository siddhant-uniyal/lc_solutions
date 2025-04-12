class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>>bfs;
        vector<vector<bool>>memo(n , vector<bool>(1<<n , false));
        for(int i = 0 ; i < n ; ++i){
            bfs.emplace(i , (1<<i));
            memo[i][1<<i] = true;
        }
        int len = 0;
        while(!bfs.empty()){
            int sz = bfs.size();
            while(sz--){
                auto [src , vis] = bfs.front();
                bfs.pop();
                if(vis == (1<<n) - 1) return len;
                for(int nxt : graph[src]){
                    int nvis = vis|(1<<nxt);
                    if(!memo[nxt][nvis]){
                        bfs.emplace(nxt , nvis);
                        memo[nxt][nvis] = true;
                    }
                }
            }
            ++len;
        }
        return -1;
    }
};