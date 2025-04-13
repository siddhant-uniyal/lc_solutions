class Solution {
public:
    long long minimumSteps(string s) {
        // 101001
        long long ans = 0;
        int n = s.size();
        long long ones = 0;
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == '1') ++ones;
            else ans += ones;
        }
        return ans;
    }
};