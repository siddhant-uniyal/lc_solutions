class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int>occ(value);
        for(int i : nums) ++occ[(i%value + value)%value];
        int mn = n + 1;
        for(int i = 0 ; i < value ; ++i){
            if(!occ[i]) return i;
            mn = min(occ[i] , mn);
        }
        int ans = value*mn;
        for(int i = 0 ; i < value ; ++i){
            if(occ[i] <= mn) return ans + i;
        }    
        return -1;
    }
};