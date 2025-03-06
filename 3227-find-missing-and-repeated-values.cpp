class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n*n;
      
        long long SN = N*(N+1)/2;
        long long SS = N*(N+1)*(2*N+1)/6;
        
     
        long long sn = 0LL , ss = 0LL;
       
        for(auto &v : grid){
            for(int &i : v) sn+=i , ss+=1LL*i*i;
            }
        long long diff = SN - sn; // m - r
        long long diffs = SS - ss; //m^2 - r^2 = (m-r)(m+r)
        
        long long sum = diffs/diff;
        
        int r = (sum-diff)/2;
        int m = sum-r;
     
        return {r,m};
                
    }
};