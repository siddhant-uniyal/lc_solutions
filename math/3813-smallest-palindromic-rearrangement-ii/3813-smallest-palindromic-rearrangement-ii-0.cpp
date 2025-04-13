class Solution {
public:
    string smallestPalindrome(string s, int k) {
        /*
        only try generating permutations with first half
        try smallest possible character 
        get all permutations
        if >=k : include
        else , go to next , but subtract from k first
        */

        int n = s.size();
        string odd = (n&1) ? string(1 , s[n/2]) : ""; //s already palin
        
        vector<int>occ(26);
        for(int i = 0 ; i < n ; ++i){
            if((n&1) and i == n/2) continue;
            ++occ[s[i] - 'a'];
        }
        int tot = 0;
        for(int i = 0 ; i < 26 ; ++i){
            occ[i]/=2; //first half
            tot += occ[i]; //helps in nCr
        }
        auto nCr = [&](int n , int r) -> int{
            r = min(r , n - r);
            long res = 1;
            for(int i = 0 ; i < r ; ++i){
                res *= (n - i);
                res /= (i + 1);
                //nCr = n * (n - 1) * .. (n - r + 1) / r!
                if(res >= k) return k;
            }
            return (int)res;
        };
        //start filling
        string ans = "";
        for(int i = 0 ; i < n/2 ; ++i){
            bool could_fill = false;
            for(int j = 0 ; j < 26 ; ++j){
                if(!occ[j]) continue;
                --occ[j]; //backtrack later
                --tot;
                int ttot = tot;
                long perms = 1;
                for(int l = 0 ; l < 26 ; ++l){
                    if(!occ[l]) continue;
                    perms*=nCr(ttot , occ[l]);
                    if(perms >= k) break;
                    ttot -= occ[l];
                }
                if(perms >= k){
                    ans += 'a' + j;
                    // --tot;
                    could_fill = true;
                    break;
                }
                k -= perms;
                ++occ[j];
                ++tot;
            }
            if(!could_fill) return "";
        }
        string revans = ans;
        reverse(revans.begin() , revans.end());
        return ans + odd + revans;
    }
};