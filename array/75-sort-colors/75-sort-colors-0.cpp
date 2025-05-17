class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0 , oStart = 0 , tExpect = n - 1;
        while(ptr <= tExpect){
            if(nums[ptr] == 0){
                swap(nums[ptr] , nums[oStart]);
                ++oStart;
                ++ptr;
            }
            else if(nums[ptr] == 2){
                swap(nums[ptr] , nums[tExpect]);
                --tExpect;
            }
            else ++ptr;
        }
    }
};