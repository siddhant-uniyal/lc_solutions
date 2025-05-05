class Solution {
public:
    int numTilings(int n) {
        /*
        at 0,x : either fill a vertical : 0,x+1
        or fill a horizontail : fill one more beneath it , then 0,x+2
        fill a tromino 2 ways : 0,x+3
        */
        vector<int>dp(n + 1 , 0);
        dp[n] = 1;
        for(int i = n - 1 ; i >= 0 ; --i){
            int vert = dp[i + 1]; //always possible
            int horz = (n - i >= 2) ? dp[i + 2] : 0;
            int tromi = (n - i >= 3) ? 2*dp[i + 3] : 0;
            dp[i] = vert + horz + tromi;
            dp[i]%=1000000007;
        }
        return dp[0];
    }
};