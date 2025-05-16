class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int decrem = 0 , end = -1;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(i == end){
                decrem = 0 , end = -1;
            }
            if(nums[i] - decrem != 0){
                if(nums[i] < decrem) return false;
                end = i + k;
                decrem = nums[i] - decrem;
            }
        }
        return true;
    }
};