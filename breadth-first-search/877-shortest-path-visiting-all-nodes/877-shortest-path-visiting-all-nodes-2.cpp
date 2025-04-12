class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        /*
        shortest path : bfs
        at each node , keep track of visited nodes , including current node
        this node will go to each of its neighbours and try visiting them
        so , done[node][mask] = true
        now it will try done[nxt][mask|(1<<nxt)]
        why | and not ^ ? :
            here revisiting a node is sometimes necessary , see testcase 1. 0 -> 1 -> 0.
            src -> nxt. at src , vis1 . at nxt , vis1|(1<<nxt). if you try to go from nxt to src , cant say its invalid immediately. do vis1|(1<<nxt)|(1<<src) , and see if src has ever had this visited mask. if it hasnt , then it will represent the 0->1->0 case at src.

        optimization -> multi source bfs
        */
        int n = graph.size();
        queue<pair<int,int>>bfs;
        vector<vector<bool>>done(n , vector<bool>(1<<n , false));
        for(int i = 0 ; i < n ; ++i){
            bfs.emplace(i , (1<<i));
            done[i][1<<i] = true;
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
                    if(!done[nxt][nvis]){
                        bfs.emplace(nxt , nvis);
                        done[nxt][nvis] = true;
                    }
                }
            }
            ++len;
        }
        return -1;
    }
};