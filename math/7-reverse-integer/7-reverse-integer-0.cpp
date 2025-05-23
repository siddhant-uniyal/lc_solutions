class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int comp = (INT_MAX - max(0 , x%10))/10;
            if(res > comp) return 0;
            res = res*10 + (x%10);
            x/=10;
        }
        return res;
    }
};
