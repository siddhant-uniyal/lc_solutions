class Solution {
public:
    int lastRemaining(int n) {

        // 1 : 1
        // 1 2 : 2
        // 1 2 3 : 2
        // 1 2 3 4 : 2
        // 1 2 3 4 5 : 2
        // 1 2 3 4 5 6 : 4
        // 1 2 3 4 5 6 7 : 4
        // 1 2 3 4 5 6 7 8 : 6
        // 1 2 3 4 5 6 7 8 9 : 6
        // 1 2 3 4 5 6 7 8 9 10 : 8
        // 1 2 3 4 5 6 7 8 9 10 11 : 8
        // 1 2 3 4 5 6 7 8 9 10 11 12 : 6

        // 2 4 6 8 10 12

        //even -> odd : ans[odd] = [even]
        //ans[1] = 1 , ans[2] = 2
        //ans[i] = ans[i - 1] : if i = odd
        //else ans[i] = i - 2*(ans[i/2] - 1)

        auto dfs = [&](int n , auto &&self) -> int{
            if(n <= 2) return n;
            if(n&1) return self(n - 1 , self);
            return n - 2*(self(n/2 , self) - 1);
        };
        return dfs(n , dfs);
    }
};