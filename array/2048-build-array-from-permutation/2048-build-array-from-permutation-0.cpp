class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        //dfs , connected components
        //a -> b , b recieves a and sends b
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] < 0) continue;
            int idx = nums[i];
            int lastFill = nums[nums[i]];
            while(idx != i){
                int nxt = nums[idx];
                nums[idx] = -nums[nxt] - 1;
                idx = nxt;
            }
            nums[i] = -lastFill -1;
        }
        for(int i = 0 ; i < n ; ++i) nums[i] = -nums[i] - 1;
        return nums;
    }
};