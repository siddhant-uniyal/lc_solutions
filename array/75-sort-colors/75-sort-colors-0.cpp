class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0 , oStart = 0 , tExpect = n - 1;
        /*
        assume problem already solved
        [0][1]...[2]
              ^
              |
              ptr
        if 1 , just extend ones
        if 0 : 001110 : 000111 , so swap with first 1
        if 2 : shift to the back 
        */
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