class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        // 0 1 2 3 3 6 5 4

        /*
        4 : 3
        0 : 1 
        */

        // 2
        // 4
        // 1
        int n = nums.size();
        unordered_map<int,int>mp;
        int mxOcc = 0 , req = 0;
        for(int i = 0 ; i < n/2 ; ++i){
            int diff = abs(nums[i] - nums[n - i - 1]);
            ++mp[diff];
            if(mp[diff] > mxOcc){
                mxOcc = mp[diff];
                req = diff;
            }
        }
        // cout << req << endl;
        int ans = 0;
        for(int i = 0 ; i < n/2 ; ++i){
            int diff = abs(nums[i] - nums[n - i - 1]);
            if(diff == req) continue;
            if(nums[i] + req > k and nums[i] - req < 0) ans += 2;
            else ++ans;
        }
        return ans;
    }
};