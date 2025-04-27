class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i =  0 ; i + 2  < n ; ++i){
            unordered_map<int,int>mp;
            ++mp[nums[i + 1] - nums[i]];
            for(int j = i + 2 ; j < n ; ++j){
                int diff = nums[j] - nums[j - 1];
                ++mp[nums[j] - nums[j - 1]];
                if(mp[diff] > 1){
                    ans += (n - j);
                    break;
                }
            }
        }
        return ans;
    }
};