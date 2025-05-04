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
            int i = m - 1;
            int cnt = pills;
            multiset<int>mst(workers.begin() + sz - m , workers.end());
            while(i >= 0 and !mst.empty()){
                int strongest = *mst.rbegin();
                if(strongest >= tasks[i]){
                    mst.erase(prev(mst.end()));
                }
                else{
                    if(cnt == 0) break;
                    int req = max(0 , tasks[i] - strength);
                    auto it = mst.lower_bound(req);
                    if(it == mst.end()) break;
                    --cnt;
                    mst.erase(it);
                }
                --i;
            }
            if (i >= 0) r = m;
            else l = m + 1;
        }
        return l - 1;
    }
};