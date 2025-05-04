class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 0;
        vector<int>occ(100);
        for(int i = 0 ; i < n ; ++i){
            int x = min(v[i][0] , v[i][1]);
            int y = max(v[i][0] , v[i][1]);
            ans += occ[x*10 + y];
            ++occ[x*10 + y];
        }
        return ans;
    }
};