class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin() , v.end());
        vector<vector<int>>ans;
        int n = v.size();
        // -1 -1 0 1 2 -4
        for(int i = 0 ; i + 2 < n ; ++i){
            if(i and v[i] == v[i - 1]) continue;
            int j = i + 1 , k = n - 1;
            while(j < k){
                int sum = v[i] + v[j] + v[k];
                if(sum == 0){
                    ans.push_back({v[i] , v[j] , v[k]});
                    while(++j < k and v[j] == v[j - 1]);
                    while(--k > j and v[k] == v[k + 1]);
                }
                else if(sum <= 0){
                    while(++j < k and v[j] == v[j - 1]);
                }
                else while(--k > j and v[k] == v[k + 1]);
            }
        }
        return ans;
    }
};