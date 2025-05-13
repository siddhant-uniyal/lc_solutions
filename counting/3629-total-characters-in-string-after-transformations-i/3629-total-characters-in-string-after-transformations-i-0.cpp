class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        //26 * t , brute force
        vector<int>occ(26);
        const int MOD = 1e9 + 7;
        for(char c : s) ++occ[c - 'a'];
        for(int i = 0 ; i < t ; ++i){
            int prev = occ[0];
            occ[0] = 0;
            for(int j = 1 ; j < 26 ; ++j){
                int oel = occ[j];
                occ[j] = prev;
                if(j == 25){
                    occ[0] = oel;
                    occ[1] += oel;
                    occ[1]%=MOD;
                }
                prev = oel;
            }
        }
        int ans = 0;
        for(int i : occ) ans = (ans + i)%MOD;
        return ans;
    }
};