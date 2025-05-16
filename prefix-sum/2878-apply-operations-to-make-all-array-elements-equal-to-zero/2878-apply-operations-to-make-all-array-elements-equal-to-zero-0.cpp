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
                decrem -= nums[idx];
            }
            if(nums[i] < decrem) return false;
            if(nums[i] - decrem != 0){
                if(i + k > n) return false;
                decrem = nums[i];
                q.push(i);
            }
        }
        return true;
    }
};