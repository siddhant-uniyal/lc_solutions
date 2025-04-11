class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        /*
        divide into k running subarrays , cost = sum(first + last)
        [   ][   ] -> last of first and first of second are clubbed together

        so maybe get v[i] + v[i + 1] , take max k - 1 and min k - 1 ??
        */
        int n = v.size();
        vector<int>psum;
        for(int i = 0 ; i + 1 < n ; ++i){
            psum.push_back(v[i] + v[i + 1]); 
        }
        int sz = psum.size();
        // sort(psum.begin() , psum.end());
        nth_element(psum.begin() , psum.begin() + (k - 1) , psum.end());
        long long MN = 0LL;
        for(int i = 0 ; i < k - 1 ; ++i){
            MN += psum[i];
        }
        nth_element(psum.begin() , psum.begin() + (sz - k + 1) , psum.end());
        long long MX = 0LL;
        for(int i = sz - 1 ; i >= sz - k + 1 ; --i){
            MX += psum[i];
        }
        return MX - MN;
    }
};