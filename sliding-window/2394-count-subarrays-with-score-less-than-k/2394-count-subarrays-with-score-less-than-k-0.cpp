using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        ll score = 0LL;
        ll sum = 0LL;
        ll ans = 0LL;
        for(int r = 0 ; r < n ; ++r){
            sum += 1LL*nums[r];
            score = 1LL*(r - l + 1)*sum;
            while(l <= r and score >= k){
                sum -= nums[l];
                ++l;
                score = 1LL*(r - l + 1)*sum;
            }
            // cout << l << " " << r << endl;
            ans += 1LL*(r - l + 1);
        }
        return ans;
    }
};