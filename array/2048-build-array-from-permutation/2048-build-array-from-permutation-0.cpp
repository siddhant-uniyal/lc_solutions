class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        //dfs , connected components
        //a -> b , b recieves a and sends b
        vector<int>vis(n);
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == nums[nums[i]]) continue;
            if(vis[i]) continue;
            vis[i] = 1;
            // cout << "ok" << endl;
            int idx = nums[i];
            int lastFill = nums[nums[i]];
            while(idx != i){
                vis[idx] = 1;
                int nxt = nums[idx];
                nums[idx] = nums[nxt];
                idx = nxt;
            }
            nums[i] = lastFill;
        }
        return nums;
    }
};