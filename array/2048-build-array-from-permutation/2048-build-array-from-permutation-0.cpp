class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        //dfs , connected components
        //a -> b , b recieves a and sends b
        int remain = n;
        for(int i = 0 ; i < n ; ++i){
            if(remain == 0) break;
            int idx = nums[i];
            int lastFill = nums[nums[i]];
            --remain;
            while(idx != i){
                --remain;
                int nxt = nums[idx];
                nums[idx] = nums[nxt];
                idx = nxt;
            }
            nums[i] = lastFill;
        }
        return nums;
    }
};