class Solution {
public:
    string smallestPalindrome(string s, int k) {

        int n = s.size();
        string odd = (n&1) ? string(1 , s[n/2]) : "";

        vector<int>occ(26);
        for(int i = 0 ; i < n ; ++i){
            if((n&1) and (i == n/2)) continue;
            ++occ[s[i] - 'a'];
        }

        for(int i = 0 ; i < 26 ; ++i){
            occ[i]/=2;
        }

        auto nCr = [&](int n , int r) -> int{
            r = min(r , n - r);
            int res = 1;
            for(int i = 0 ; i < r ; ++i){
                res *= (n - i);
                res /= (i + 1);
                if(res >= k) return k;
            }
            return res;
        };

        string ans = "";
        for(int i = 0 ; i < n/2 ; ++i){
            for(int j = 0 ; j < 26 ; ++j){
                if(!occ[j]) continue;
                int perms = 1;
                --occ[j];
                int ttot =  accumulate(occ.begin() , occ.end() , 0);
                for(int kk = 0 ; kk < 26 ; ++kk){
                    if(!occ[kk]) continue;
                    perms *= nCr(ttot , occ[kk]);
                    ttot -= occ[kk];
                    if(perms >= k){
                        perms = k;
                        break;
                    }
                }
                if(perms >= k){
                    ans += 'a' + j;
                    break;
                }
                k -= perms;
                ++occ[j];
            }
        }
        string tans = ans;
        reverse(tans.begin() , tans.end());
        return ans + odd + tans;
    }
};