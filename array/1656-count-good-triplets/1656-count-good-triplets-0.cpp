class Solution {
public:
    int countGoodTriplets(vector<int>& v, int a, int b, int c) {
        int n = v.size();
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                for(int k = j + 1 ; k < n ; ++k){
                    ans += (abs(v[i] - v[j]) <= a) and (abs(v[j] - v[k]) <= b) and (abs(v[i] - v[k]) <= c);
                }
            }
        }
        return ans;
    }
};