int dp[50][50][101][11];
class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        if(n == 2) return l * time[0];
        /*
        at ind , i can merge with ind - 1 or not.
        if i dont (close the subarray) , ind - 1 is finalized , so calculate cost right now and add

        ind , l , prevSum , merges : at index ind , the previous subarray starts at l , the sum of 2nd previous subarray is prevSum , remaining merges = merges

        if i choose to close here , ind + 1 must get currSum. that doesnt need to be maintained , prefix sum

        if i choose to keep open (merge) , prev Sum DOES NOT CHANGE.
        */
        memset(dp , -1 , sizeof(dp));
        vector<int>pref(n);
        for(int i = 0 ; i < n ; ++i){
            pref[i] = (i ? pref[i - 1] : 0) + time[i];
        }

        auto dfs = [&](int ind , int l , int prevSum , int merges , auto &&self) -> int{
            // cout << ind << " " << l << " " << prevSum << " " << merges << endl;
            if(ind == n){
                int closeCost = prevSum * (position[n - 1] - position[l - 1]);
                // cout << closeCost << endl;
                return merges == 0 ? closeCost : 1e9;
            }
            if(merges < 0) return 1e9;
            if(dp[ind][l][prevSum][merges] != -1) return dp[ind][l][prevSum][merges];
            // if(merges == 0) return 1e9;
            /*
            0 , 3 , 8 , 10
            8 recieves : [0] [3) 8 10 => ) means its open
            10 recieves : [0] [3] [8) 10 OR [0] [3 8) 10

            so at 8 , closing it will use prevSum ([0] sum) , and pass on prefix sum , and merges stay same.
            */
            int closeCost = prevSum * (position[ind - 1] - position[l - 1]);
            int closeGive = pref[ind - 1] - pref[l - 1];
            int closeHere = closeCost + self(ind + 1 , ind , closeGive , merges , self);
            //keeping open == merging
            int keepOpen = self(ind + 1 , l , prevSum , merges - 1 , self);
            return dp[ind][l][prevSum][merges] = min(closeHere , keepOpen);
        };
        return dfs(2 , 1 , time[0] , k , dfs);
    }
};