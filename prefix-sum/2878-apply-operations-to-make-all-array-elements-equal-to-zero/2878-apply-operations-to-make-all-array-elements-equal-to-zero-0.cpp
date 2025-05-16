class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int req = 0;
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; ++i){
            if(!q.empty() && i == q.front().first + k){
                req -= q.front().second;
                q.pop();
            }
            if(nums[i] != req){
                if(i + k > n || nums[i] < req) return false;
                q.emplace(i , nums[i] - req);
                req = nums[i];
            }
        }
        return true;
    }
};