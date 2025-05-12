class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>occ(10);
        for(int i : digits) ++occ[i];
        vector<int>ans;
        for(int i = 1 ; i < 10 ; ++i){
            if(!occ[i]) continue;
            for(int j = 0 ; j < 10 ; ++j){
                if(!occ[j] || (j == i && occ[i] < 2)) continue;
                for(int k = 0 ; k < 10 ; k += 2){
                    int avail = occ[k] - (i == k) - (j == k);
                    if(!avail) continue;
                    ans.push_back(100*i + 10*j + k);
                }
            }
        }
        return ans;
    }
};