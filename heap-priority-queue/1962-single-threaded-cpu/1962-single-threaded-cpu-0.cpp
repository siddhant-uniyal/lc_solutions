class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>ids(n);
        iota(ids.begin() , ids.end() , 0);
        sort(ids.begin() , ids.end() , [&](const auto &a , const auto &b){
            return tasks[a][0] == tasks[b][0] && tasks[a][1] == tasks[b][1] ? a < b : tasks[a] < tasks[b];
            });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.emplace(tasks[ids[0]][1] , ids[0]);
        vector<int>ans(n);
        int thresh = 0;
        int j = 1;
        for(int i = 0 ; i < n ; ++i){
            if(pq.empty() && i < n) pq.emplace(tasks[ids[i]][1] , ids[i]) , j = i + 1;
            auto [cost , src] = pq.top();
            pq.pop();
            ans[i] = src;
            thresh = max(tasks[src][0] + cost , thresh);
            while(j < n && tasks[ids[j]][0] <= thresh) pq.emplace(tasks[ids[j]][1] , ids[j]) , ++j;
        }
        return ans;
    }
};