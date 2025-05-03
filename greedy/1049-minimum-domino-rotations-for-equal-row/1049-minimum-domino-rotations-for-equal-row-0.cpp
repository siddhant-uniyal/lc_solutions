class Solution {
public:
    int minDominoRotations(vector<int>& t , vector<int>& b) {
        int n = t.size();
        int ans = n + 1;
        for(int i = 1 ; i <= 6 ; ++i){
            int makeT = 0 , makeB = 0;
            for(int j = 0 ; j < n ; ++j){
                int x = t[j] , y = b[j];
                if(x != i and y != i){
                    makeT = n + 1 , makeB = n + 1;
                    break;
                }
                makeT += (x != i);
                makeB += (y != i);
            }
            ans = min({ans , makeT , makeB});
        }
        return ans == n + 1 ? -1 : ans;
    }
};