class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int>q;
        int decrem = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!q.empty() && i == q.front() + k){
                int idx = q.front();
                q.pop();
                decrem = max(0 , decrem - nums[idx]);
            }
            if(nums[i] < decrem) return false;
            if(nums[i] - decrem != 0){
                decrem = nums[i];
                q.push(i);
            }
        }
        return q.empty() || q.back() + k <= n;
    }
};