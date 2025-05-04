class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pairs(k + 1); //number of pairs with diff = k as one op
        vector<int>freq(k + 1);
        for(int i = 0 ; i < n/2 ; ++i){
            int diff = abs(nums[i] - nums[n - 1 - i]);
            ++freq[diff];
            int end1 = max(nums[i] , k - nums[i]);
            int end2 = max(nums[n - 1 - i] , k - nums[n - 1 - i]);
            int end = max(end1 , end2);
            /*
            ++pairs[0];
            if(end + 1 <= k) --pairs[end + 1];

            instead of this , all i had to was do ++pairs[end] , why?
            because , [0 ... end][end + 1 .. k]
                         1opps       2opps
            achieving any value of diff from [0..end] means i can also achieve a value of diff - 1
            but not vice versa
            so ++pairs[0] was wrong , but ++pairs[end] is ok , but then you have to go in reverse to get count of pairs that have this diff as 1 op.
             
            */
            ++pairs[end];
        }
        int ans = 2*n + 1;
        for(int i = k ; i >= 0 ; --i){
            if(i + 1 <= k) pairs[i] += pairs[i + 1];
            int already = freq[i];
            int oneOpps = pairs[i] - already; //because above loop also counts diffs that are already achieved as 1 op
            int twoOpps = n/2 - already - oneOpps;
            ans = min(ans , oneOpps + 2*twoOpps);
        }
        return ans;
    }
};