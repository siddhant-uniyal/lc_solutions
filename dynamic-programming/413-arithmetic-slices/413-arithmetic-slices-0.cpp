class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i =  0 ; i + 2 < n ; ){
            int req = nums[i + 1] - nums[i];
            int ni = -1;
            for(int j = i + 2 ; j < n ; ++j){
                int diff = nums[j] - nums[j - 1];
                if(diff != req){
                    ni = j;
                    break;
                }
                ++ans;
            }
            if(ni == -1){
                // //i+1..n-1
                // ans += (n - i - 1) * (n - i - 2)/2;
                ++i;
            }
        }
        return ans;
    }
};