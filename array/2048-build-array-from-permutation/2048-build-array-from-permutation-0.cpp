class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        //dfs , connected components
        //a -> b , b recieves a and sends b
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] < 0) continue;
            nums[i] *= -1;
            int idx = nums[i];
            int lastFill = nums[abs(nums[i])];
            while(idx != i){
                int nxt = nums[abs(idx)];
                nums[abs(idx)] = -nums[abs(nxt)];
                idx = nxt;
            }
            nums[i] = -lastFill;
        }
        for(int i = 0 ; i < n ; ++i){
            nums[i] = max(nums[i] , -nums[i]);
        }
        return nums;
    }
};