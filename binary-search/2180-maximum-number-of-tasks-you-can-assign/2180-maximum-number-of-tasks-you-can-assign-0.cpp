class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        /*
        sort tasks and workers
        if you can give pill , give it

        10 12

        5 , 6 pills=1 , str = 4

        i , j , x

        if i give : 1 + (i + 1 , j + 1 , x - 1)
        i dont : (i , j + 1 , x)


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
        int i = n - 1 , j = m - 1;
        int ans = 0;
        while(i >= 0 and j >= 0){
            if(workers[ids2[j]] >= tasks[ids1[i]]){
                ++ans;
                --i , --j;
            }
            else{
                if(pills > 0){
                    if(workers[ids2[j]] + strength >= tasks[ids1[i]]){
                        ++ans;
                        --i , --j;
                        --pills;
                    }
                    else --i;
                }
                else --i;
            }
        }

        return ans;
    }
};