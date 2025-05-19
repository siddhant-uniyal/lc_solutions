class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        }
        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]){
            return "isosceles";
        }
        sort(nums.begin() , nums.end());
        return nums[0] + nums[1] > nums[2] ? "scalene" : "none";
    }
};