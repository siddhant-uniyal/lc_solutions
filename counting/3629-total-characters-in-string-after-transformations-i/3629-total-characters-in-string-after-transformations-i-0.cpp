class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        //26 * t , brute force
        vector<int>occ(26);
        const int MOD = 1e9 + 7;
        for(char c : s) ++occ[c - 'a'];
        for(int i = 0 ; i < t ; ++i){
            vector<int>nocc(26);
            for(int j = 0 ; j < 26 ; ++j){
                int curr = occ[j];
                nocc[(j + 1)%26] = curr;
                if(j == 25){
                    nocc[1] += curr;
                    nocc[1]%=MOD;
                }
            }
            occ = nocc;
        }
        int ans = 0;
        for(int i : occ) ans = (ans + i)%MOD;
        return ans;
    }
};