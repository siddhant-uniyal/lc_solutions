// class Solution {
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n = graph.size();
//         int ans = -1;
//         for(int i = 0 ; i < n ; ++i){
//             queue<tuple<int,int,int>>bfs;
//             bfs.emplace(i , (1<<i) , -1);
//             int len = 0;
//             bool done = false;
//             while(!bfs.empty()){
//                 int sz = bfs.size();
//                 while(sz--){
//                     auto [src , vis , par] = bfs.front();
//                     bfs.pop();
//                     if(vis == (1<<n) - 1){
//                         done = true;
//                         break;
//                     }
//                     bool couldGo = false;
//                     for(int nxt : graph[src]){
//                         if(!(vis&(1<<nxt))){
//                             couldGo = true;
//                             bfs.emplace(nxt , vis^(1<<nxt) , src);
//                         }
//                     }
//                     if(!couldGo){
//                         bfs.emplace(par , vis^(1<<src) , src);
//                     }
//                 }
//                 if(done) break;
//                 ++len;
//             }
//             if(ans == -1) ans = len;
//             else ans = min(ans , len);
//         }
//         return ans;
//     }
// };
