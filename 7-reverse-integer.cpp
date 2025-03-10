class Solution {
public:
    int reverse(int x) {
        long long ans = 0LL;
        while(x){
            ans = ans*10 + x%10;
            // cout << ans << endl;
            x /= 10;
        }
        // cout << ans << endl;
        return (int)ans == ans ? ans : 0;
    }
};