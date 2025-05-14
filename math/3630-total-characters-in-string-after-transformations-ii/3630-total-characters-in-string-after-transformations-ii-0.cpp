class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int>occ(26);
        for(char c : s) ++occ[c - 'a'];
        for(int i = 0 ; i < t ; ++i){
            vector<int>nocc(26);
            for(int j = 0 ; j < 26 ; ++j){
                if(!occ[j]) continue;
                for(int k = 1 ; k <= nums[j] ; ++k){
                    nocc[(j + k)%26] += occ[j];
                }
            }
            occ = nocc;
        }
        int ans = 0;
        for(int i : occ) ans += i , ans %= MOD;
        return ans;
    }
};