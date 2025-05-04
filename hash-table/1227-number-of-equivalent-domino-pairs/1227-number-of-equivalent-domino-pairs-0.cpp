class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                for(int k = 0 ; k < 2 ; ++k){
                    for(int l = 0 ; l < 2 ; ++l){
                        if(dominoes[i][k] == dominoes[j][l]){
                            ++ans;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};