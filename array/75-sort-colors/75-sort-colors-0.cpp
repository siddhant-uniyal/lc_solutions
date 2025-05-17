class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n - 1;
        while(i <= j){
            if(nums[i] == 2){
                while(j > i && nums[j] == 2){
                    --j;
                }
                swap(nums[i] , nums[j]);
                --j;
            }
            ++i;
        }
        i = 0;
        while(i <= j){
            if(nums[i] == 1){
                while(j > i && nums[j] == 1){
                    --j;
                }
                swap(nums[i] , nums[j]);
                --j;
            }
            ++i;
        }
    }
};