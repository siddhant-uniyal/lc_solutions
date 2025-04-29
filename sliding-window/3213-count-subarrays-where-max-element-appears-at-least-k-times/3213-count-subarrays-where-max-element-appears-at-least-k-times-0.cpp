class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin() , nums.end());
        int l = 0;
        int cnt = 0;
        long long ans = 0LL;
        int n = nums.size();
        for(int r = 0 ; r < n ; ++r){
            cnt += (nums[r] == mx);
            while(l <= r and cnt == k){
                ans += 1LL*(n - r);
                cnt -= (nums[l] == mx);
                ++l;
            }
        }
        return ans;
    }
};