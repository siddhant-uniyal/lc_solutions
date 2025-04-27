class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int l = 0;
        unordered_map<int,int>occ;
        occ[nums[1] - nums[0]] = 1;
        int ans = 0;
        for(int r = 2 ; r < n ; ++r){
            int diff = nums[r] - nums[r - 1];
            ++occ[diff];
            while(occ[diff] >= 2){
                ans += (n - r);
                --occ[nums[l + 1] - nums[l]];
                ++l;
            }
        }
        return ans;
    }
};