class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        /*
        sort tasks and workers
        if you can give pill , give it

        10 12

        5 , 6 pills=1 , str = 4
        */
        int n = tasks.size();
        int m = workers.size();
        vector<int>ids1(n);
        vector<int>ids2(m);
        iota(ids1.begin() , ids1.end() , 0);
        iota(ids2.begin() , ids2.end() , 0);
        sort(ids1.begin() , ids1.end() , [&](const int &a , const int &b){
            return tasks[a] < tasks[b];
        });
        sort(ids2.begin() , ids2.end() , [&](const int &a , const int &b){
            return workers[a] < workers[b];
        });
        int i = 0 , j = 0;
        int ans = 0;
        while(i < n and j < m){
            if(workers[ids2[j]] >= tasks[ids1[i]]){
                ++ans;
                ++i , ++j;
            }
            else{
                if(workers[ids2[j]] + strength >= tasks[ids1[i]] and pills > 0){
                    ++ans;
                    ++i , ++j;
                    --pills;
                }
                else ++j;
            }
        }
        return ans;
    }
};