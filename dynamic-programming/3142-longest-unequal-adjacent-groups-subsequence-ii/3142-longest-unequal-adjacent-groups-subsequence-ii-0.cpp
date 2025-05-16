class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int>dp(n + 1) , parent(n);
        int mx = 1;
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
        for(int i = n ; i >= 1 ; --i){
            dp[i] = 1;
            for(int j = i + 1 ; j <= n ; ++j){
                int sz1 = words[i - 1].size();
                int sz2 = words[j - 1].size();
                if(sz1 != sz2) continue;
                if(groups[i - 1] == groups[j - 1]) continue;
                int dist = 0;
                for(int k = 0 ; k < sz1 ; ++k){
                    dist += words[i - 1][k] != words[j - 1][k];
                }
                if(dist != 1) continue;
                if(1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    parent[i - 1] = j - 1;
                }
            }
            mx = max(mx , dp[i]);
        }
        vector<string>ans;
        int st = 0;
        bool found = false;
        while(st < n){
            if(parent[st] == st){
                if(found){
                    ans.push_back(words[st]);
                    break;
                }
                ++st;
            }
            else if(found || dp[st + 1] == mx){
                ans.push_back(words[st]);
                found = true;
                st = parent[st];
            }
            else ++st;
        }
        if(ans.empty()) return {words[0]};
        return ans;
    }
};