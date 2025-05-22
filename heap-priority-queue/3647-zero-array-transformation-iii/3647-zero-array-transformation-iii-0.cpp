class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        /*
        
        every guy is turned to 0 by some query i
        this means , every query
        0,2 1,2 1,3 1,3

        2
        0 1 2
        */
        int n = nums.size();
        int sz = queries.size();
        int l = 0 , r = sz + 1;
        while(l < r){
            int m = l + ((r-l)>>1);
            vector<int>pref(n);
            for(int i = 0 ; i < sz - m ; ++i){
                ++pref[queries[i][0]];
                if(queries[i][1] + 1 < n) --pref[queries[i][1]];
            }
            bool ok = true;
            for(int i = 0 ; i < n ; ++i){
                pref[i] += i ? pref[i - 1] : 0;
                if(pref[i] < nums[i]){
                    ok = false;
                    break;
                }
            }
            if(!ok) r = m;
            else l = m + 1;
        }
        return l - 1;
    }
};