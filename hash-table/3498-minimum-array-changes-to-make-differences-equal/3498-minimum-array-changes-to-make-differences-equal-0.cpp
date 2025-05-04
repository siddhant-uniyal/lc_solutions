class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ops(k + 1);
        vector<int>freq(k + 1);
        for(int i = 0 ; i < n/2 ; ++i){
            int diff = abs(nums[i] - nums[n - 1 - i]);
            ++freq[diff];
            int end1 = max(nums[i] , k - nums[i]);
            int end2 = max(nums[n - 1 - i] , k - nums[n - 1 - i]);
            int end = max(end1 , end2);
            // for(int j = 0 ; j <= k ; ++j){
            //     ops[j] += 1 + (j > end);
            // }
            // --ops[diff];
            ++ops[end];
        }
        int ans = 2*n + 1;
        for(int i = k ; i >= 0 ; --i){
            if(i + 1 <= k) ops[i] += ops[i + 1];
            int already = freq[i];
            int oneOps = ops[i] - already;
            int twoOps = n/2 - already - oneOps;
            ans = min(ans , oneOps + 2*twoOps);
        }
        return ans;
    }
};