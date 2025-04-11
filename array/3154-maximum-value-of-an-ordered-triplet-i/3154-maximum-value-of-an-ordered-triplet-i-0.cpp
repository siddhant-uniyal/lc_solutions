class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        int n = v.size();
        long long ans = 0LL;
        long long diff = v[0] - v[1];
        long long mx = max(v[0] , v[1]);
        for(int k = 2 ; k < n ; ++k){
            ans = max(ans , 1LL * diff * v[k]);
            diff = max(diff , mx - v[k]);
            mx = max(mx , 1LL*v[k]);
        }
        return ans;
    }
};