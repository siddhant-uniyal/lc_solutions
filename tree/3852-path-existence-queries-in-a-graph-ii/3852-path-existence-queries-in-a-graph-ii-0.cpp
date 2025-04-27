class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>ids(n);
        iota(ids.begin() , ids.end() , 0);
        sort(ids.begin() , ids.end() , [&](const int &a , const int &b){
            return nums[a] < nums[b];
        });
        int ptr = n - 1;
        int LOG = 0;
        while((1<<LOG) <= n) ++LOG;
        vector<vector<int>>jump(n , vector<int>(LOG , -1));
        jump[ids.back()][0] = -1;
        for(int i = n - 2 ; i >= 0 ; --i){
            while(ptr > i and nums[ids[ptr]] - nums[ids[i]] > maxDiff) --ptr;
            if(ptr > i){
                jump[ids[i]][0] = ids[ptr];
            }
        }
        for(int j = 1 ; j < LOG ; ++j){
            for(int i = 0 ; i < n ; ++i){
                if(jump[i][j - 1] != -1){
                    jump[i][j] = jump[jump[i][j-1]][j-1];
                }
            }
        }
        vector<int>ans;
        for(auto &v : queries){
            int ql = v[0] , qr = v[1];
            if(nums[ql] > nums[qr]){
                swap(ql , qr);
            }
            if(nums[qr] - nums[ql] <= maxDiff){
                ans.push_back(ql != qr);
                continue;
            }
            int l = 2 , r = n;
            while(l < r){
                int m = l + ((r-l)>>1);
                int tql = ql;
                for(int i = 0 ; i < LOG ; ++i){
                    if(m&(1<<i)){
                        tql = jump[tql][i];
                        if(tql == -1 or nums[qr] - nums[tql] <= maxDiff) break;
                    }
                }
                if(tql != -1 and nums[qr] - nums[tql] <= maxDiff) r = m;
                else l = m + 1;
            }
            ans.push_back(l == n ? -1 : l);
        }
        return ans;
    }
};