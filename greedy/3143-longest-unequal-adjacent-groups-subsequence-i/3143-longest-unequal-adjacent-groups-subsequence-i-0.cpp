class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int n = groups.size();
        ans.push_back(words[0]);
        for(int i = 1 ; i < n ; ++i){
            if(groups[i] != groups[i - 1]) ans.push_back(words[i]);
        }
        return ans;
    }
};