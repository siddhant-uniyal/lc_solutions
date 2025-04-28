using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        ll sum = 0LL;
        ll ans = 0LL;
        for(int r = 0 ; r < n ; ++r){
            sum += 1LL*nums[r];
            while(l <= r and 1LL*(r - l + 1)*sum >= k){
                sum -= nums[l];
                ++l;
            }
            // cout << l << " " << r << endl;
            ans += 1LL*(r - l + 1);
        }
        return ans;
    }
};