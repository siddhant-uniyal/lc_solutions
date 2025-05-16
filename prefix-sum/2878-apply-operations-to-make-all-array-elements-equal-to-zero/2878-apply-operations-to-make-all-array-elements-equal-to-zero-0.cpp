class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int req = 0;
        queue<pair<int,int>>q;
        /*
        element must be req
        if not , has to be subtracted more to be req
        so if less than req : false
        2 2 3 1 1 0
        subtractions :
        2 2 2
            1 1 1
        so keep track of the subtraction in queue
        */
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