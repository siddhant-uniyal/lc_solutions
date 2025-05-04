class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int l = 1, r = n + 1;
        sort(tasks.begin() , tasks.end());
        sort(workers.begin() , workers.end());
        int sz = workers.size();
        while(l < r) {
            /*
            if i have to complete x tasks. 
            i will always choose smallest x
            if i can complete x , i can definitely complete x - 1
            binary search.
            choose x smallest tasks , x strongest guys.
            if the strongest guy cant complete largest task , you have to use the pill , since he was the best worker. but , using the pill on him doesnt make sense because he's still useful for the future , he's the strongest. use the pill on someone who can be a liability in the future , ie , the weakest guy.
            maybe this guy could be a problem in the future , for eg:
            tasks : 4 5 6
            workers : 3 5 6 , until task = 4 , its good. then its impossible. 
            so , if giving him a pill allows him to complete the task , do it

            this solves 3 problems :
            1) keeps the strongest guy for the future
            2) ensures that the current task gets completed
            3) only uses pills on those who absolutely need it , and uses it in the most sensible scenario
            */
            int m = l + ((r-l)>>1);
            int i = m - 1;
            int cnt = pills;
            multiset<int>mst(workers.begin() + max(0 , sz - m) , workers.end());
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