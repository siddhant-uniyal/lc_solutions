class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n - 1;
        while(i <= j){
            if(nums[i] == 2){
                swap(nums[i] , nums[j]);
                --j;
            }
            ++i;
        }
        i = 0;
        while(i <= j){
            if(nums[i] == 1){
                swap(nums[i] , nums[j]);
                --j;
            }
            ++i;
        }
    }
};