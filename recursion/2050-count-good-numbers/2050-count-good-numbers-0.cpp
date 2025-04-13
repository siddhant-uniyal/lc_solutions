using ll = long long;
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long evens = n/2LL + (n&1LL);
        long long odds = n/2LL;
        //0,2,4,6,8
        //2,3,5,7
        const int MOD = 1e9+7;
        auto binExp = [&](long long n , long long b) -> long long{
            long long res = 1;
            while(b){
                if(b&1){
                    res = (res*n)%MOD;
                }
                n = (n*n)%MOD;
                b>>=1;
            }         
            return res;   
        };
        long long res1 = binExp(5LL ,evens);
        long long res2 = binExp(4LL , odds);
        return (res1*res2)%MOD;
    }
};