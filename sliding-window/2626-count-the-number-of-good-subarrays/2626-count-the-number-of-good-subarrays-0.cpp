class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        int pairs = 0;
        long long ans = 0;
        int i = 0;
        for(int j = 0 ; j < n ; ++j){
            pairs += mp[nums[j]];
            ++mp[nums[j]];
            while(i <= j and pairs >= k){
                // cout << i << " " << j << endl;
                // cout << pairs << endl;
                // for(auto &[k,v] : mp){
                //     cout << k << " " << v << endl;
                // }
                // cout << "________" << endl;
                ans += (n - j);
                pairs -= (mp[nums[i]]-1);
                --mp[nums[i]];
                ++i;
            }
        }
        return ans;
    }
};