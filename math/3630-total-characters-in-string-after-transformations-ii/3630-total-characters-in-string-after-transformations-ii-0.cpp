class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        // vector<vector<int>>dp(26 , vector<int>())
        auto dfs = [&](char c , int ops , auto &&self) -> int{
            if(ops == 0) return 1;
            int to_return = 0;
            // cout << c << ": ";
            for(int i = 1 ; i <= nums[c - 'a'] ; ++i){
                char nxt = (c - 'a' + i)%26 + 'a';
                // cout << nxt << ", ";
                // cout << endl;
                to_return += self(nxt , ops - 1 , self);
                to_return%=MOD;
            }
            return to_return;
        };
        int ans = 0;
        for(char c : s) ans += dfs(c , t , dfs) , ans%=MOD;
        return ans;
    }
};