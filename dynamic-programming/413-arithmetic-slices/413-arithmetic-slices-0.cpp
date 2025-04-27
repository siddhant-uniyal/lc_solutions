class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i =  0 ; i + 2 < n ; ++i){
            int req = nums[i + 1] - nums[i];
            for(int j = i + 2 ; j < n ; ++j){
                int diff = nums[j] - nums[j - 1];
                if(diff != req) break;
                ++ans;
            }
        }
        return ans;
    }
};