int el2Sz[100001][79];
using ll = long long;
class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector<int>ans;
        int n = nums.size();
        int tot = 0;
        unordered_map<int,int>sizes;
        map<vector<ll> , int>memo;
        for(int i : nums){
            int oi = i;
            int sz = 0;
            while(oi) oi/=10 , ++sz;
            sizes[i] = sz;
            tot += sz;
        }
        for(int i : nums){
            ll pow = 1;
            for(int j = 0 ; j < 79 ; ++j){
                el2Sz[i][j] = (1LL*i*pow)%k;
                pow = (pow*10)%k;
            }
        }
        vector<int>parent((1<<n) + 1);
        auto dfs = [&](int mask , int tsz , ll mod , auto &&self) -> bool{
            int sz = __builtin_popcount(mask);
            if(sz == n){
                if(mod == 0){
                    return true;
                }
                return false;
            }
            if(memo.count({mask,tsz,mod})) return memo[{mask,tsz,mod}];
            for(int i = 0 ; i < n ; ++i){
                if(!(mask&(1<<i))){
                    int csz = sizes[nums[i]];
                    int iska = el2Sz[nums[i]][tsz - csz];
                    parent[mask] = i;
                    if(self(mask|(1<<i) , tsz - csz , (mod+iska)%k , self)) return memo[{mask,tsz,mod}] = true;
                    parent[mask] = -1;
                }
            }
            return memo[{mask,tsz,mod}] = false;
        };
        dfs(0 , tot , 0 , dfs);
        int mask = 0;
        for(int i = 0 ; i < n ; ++i){
            if(parent[mask] == -1) break;
            ans.push_back(nums[parent[mask]]);
            mask^=(1<<(parent[mask]));
        }
        return ans;
    }
};