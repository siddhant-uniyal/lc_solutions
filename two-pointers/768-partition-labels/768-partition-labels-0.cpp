class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>occs(26 , -1);
        for(int i = 0 ; i < n ; ++i){
            occs[s[i] - 'a'] = i;
        }
        vector<int>ans;
        int lim = 0;
        int j = 0;
        for(int i = 0 ; i < n ; ++i){
            lim = max(lim , occs[s[i] - 'a']);
            if(i == lim){
                ans.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return ans;
    }
};

//overwrite - 0