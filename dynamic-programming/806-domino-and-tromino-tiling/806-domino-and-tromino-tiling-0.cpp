long dp[2][1001][2];
class Solution {
public:
    int numTilings(int n) {
        memset(dp , 0 , sizeof(dp));
        const int MOD = 1000000007;
        dp[0][n][1] = 1;
        for(int j = n - 1 ; j >= 0 ; --j){
            for(int i = 0 ; i < 2 ; ++i){
                for(int k = 0 ; k < 2 ; ++k){
                    if(k) dp[i][j][k] += dp[0][j + 1][1]; //vert
                    //horz
                    if(n - j >= 2){
                        if(k) dp[i][j][k] += dp[0][j + 2][1];
                        else dp[i][j][k] += dp[i^1][j + 1][0];
                    }
                    //trom , 2 ways
                    if(n - j >= 1 and k) dp[i][j][k] += (dp[0][j + 1][0] + dp[1][j + 1][0]);
                    //trom , 3rd way
                    if(n - j >= 2 and !k) dp[i][j][k] += dp[0][j + 2][1];

                    dp[i][j][k] %= MOD;
                }
            }
        }
        return dp[0][0][1];
    }
};