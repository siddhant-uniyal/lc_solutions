class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        while(j < n){
            if(nums[j] != 2){
                swap(nums[i] , nums[j]);
                ++i;
            }
            ++j;
        }
        int ul = i;
        i = 0 , j = 0;
        while(j < ul){
            if(nums[j] != 1){
                swap(nums[i] , nums[j]);
                ++i;
            }
            ++j;
        }
    }
};