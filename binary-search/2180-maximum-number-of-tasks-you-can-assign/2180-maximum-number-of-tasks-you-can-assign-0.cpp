class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int l = 1, r = n + 1;
        sort(tasks.begin() , tasks.end());
        sort(workers.begin() , workers.end());
        int sz = workers.size();
        while(l < r) {
            int m = l + ((r-l)>>1);
            int i = m - 1 , j = sz - 1;
            int cnt = pills;
            while(i >= 0 and j >= 0) {
                if(workers[j] >= tasks[i]) --i, --j;
                else if(cnt > 0 and workers[j] + strength >= tasks[i]) --i, --j, --cnt;
                else break;
            }
            if (i >= 0) r = m;
            else l = m + 1;
        }
        return l - 1;
    }
};