using ll = long long;
class Solution {
public:
    vector<int> permute(int n, long long k) {
        vector<int>ans;
        vector<int>done(n + 1);
        vector<ll>fact(n + 1 , 1LL);
        for(int i = 2 ; i <= n ; ++i){
            fact[i] = min(k , i*fact[i-1]);
        }
        int toto = (n/2) + (n&1);
        int tote = (n/2);
        int donee = 0 , doneo = 0;
        for(int i = 0 ; i < n ; ++i){
            bool could_fill = false;
            for(int j = 1 ; j <= n ; ++j){
                if(done[j] or (!ans.empty() and ((ans.back()&1) == (j&1)))) continue;
                j&1 ? ++doneo : ++donee;
                int remo = toto - doneo;
                int reme = tote - donee;
                if(abs(remo - reme) > 1){
                    j&1 ? --doneo : --donee;
                    continue; //impossible to have alternating
                }
                if(fact[remo] >= k or fact[reme] >= k or fact[remo] >= ((k+fact[reme]-1)/fact[reme])){
                    //include
                    ans.push_back(j);
                    done[j] = 1;
                    could_fill = true;
                    break;
                }
                else{
                    k -= fact[remo]*fact[reme];
                    j&1 ? --doneo : --donee;
                }
            }
            if(!could_fill) return {};
        }
        return ans;
    }
};