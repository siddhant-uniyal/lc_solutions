class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 , j = 0;
        int n = nums.size();
        while(j < n){
            if(nums[j]){
                swap(nums[j] , nums[i]);
                ++i;
            }
            ++j;
        }
    }
};