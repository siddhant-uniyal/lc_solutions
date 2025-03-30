class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
        vector<vector<bool>>dp(n+1 , vector<bool>(n+1));
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j <= i ; ++j) dp[i][j] = true;
        
        int l = 0 , r = 0;
        for(int i = n - 2 ; i >= 0 ; --i){
            for(int j = i + 1 ; j < n ; ++j){
            if(s[i] == s[j] and dp[i+1][j-1]){
                dp[i][j] = true;
                if(j - i + 1 > r - l + 1)
                    l = i , r = j;
                }
                }
            }
        return s.substr(l , r - l + 1);
    }
};

//append - 3.cpp