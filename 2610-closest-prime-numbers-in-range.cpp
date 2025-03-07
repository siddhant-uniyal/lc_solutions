class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>sieve(right + 1 , true);
        sieve[0] = sieve[1] = false;
        for(int i = 2 ; i*i <= right ; ++i){
            if(sieve[i]){
                for(int j = i*i ; j <= right ; j+=i) sieve[j] = false;
                }
            }
        vector<int>ans{-1,-1};
        
        int diff = 1e6 , prev = -1;
        for(int i = left ; i <= right ; ++i){
            if(!sieve[i]) continue;
            if(prev != -1 and i - prev < diff){
                ans = {prev,i};
                diff = i - prev;
                }
            prev = i;
            }
        return ans;
    }
};