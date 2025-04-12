class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(k > sum or k < -sum) return -1;
        /*
        dp[ind][sum][prod][mode]

        150 * 1800 * 5000 * 3 -> TLE?
        nums[i] <= 12 : so , primes : 2,3,5,7,11
        the product can only have these prime factors.
        such numbers <= 5000 : only 393
        150 * 1800 * 393 * 3
        the count of possible sums is not 1800
        mode : 0 -> empty , 1 -> add , 2 -> subtract
        */
        int n = nums.size();
        map<array<int,4>,int>mp;
        auto dfs = [&](int ind , int sum , int prod , int mode , auto &&self) -> int{
            if(prod > limit) prod = limit + 1; //if prod > limit , has to be multiplied by 0 to become valid. anything * 0 = 0. so , all invalids can be considered to be the same , reduces map size 
            if(ind == n){
                return sum == k and prod <= limit and mode ? prod : -1;
            }
            if(mp.count({ind , sum , prod , mode})) return mp[{ind , sum , prod , mode}];
            return mp[{ind , sum , prod , mode}] = max(
                self(ind + 1 , sum + (mode != 2 ? nums[ind] : -nums[ind]) , (parity ? prod : 1) * nums[ind] , (mode != 2 ? 2 : 1) , self),
                self(ind + 1 , sum , prod , mode , self)
            );
        };
        return dfs(0 , 0 , 0 , 0 , dfs);
    }
};