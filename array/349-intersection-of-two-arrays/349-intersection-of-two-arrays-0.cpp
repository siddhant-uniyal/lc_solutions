class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>occ(1001);
        for(int i : nums1) occ[i] = 1;
        vector<int>ans;
        for(int i : nums2){
            if(occ1[i]){
                occ1[i] = 0;
                ans.push_back(i);
            }
        }
        return ans;
    }
};