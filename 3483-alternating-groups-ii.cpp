class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
        int ans = 0;
        int n = v.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(i == 0){
                for(int j = 1 ; j < k ; ++j){
                    cnt+=(v[j]!=v[j-1]);
                }
            }
            else{
                cnt-=(v[i]!=v[i-1]);
                cnt+=(v[(i+k-1)%n]!=v[(i+k-2)%n]);
            }
            ans += (cnt == k-1);
        }
        return ans;
    }
};