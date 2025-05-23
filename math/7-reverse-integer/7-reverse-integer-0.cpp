class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int comp1 = (INT_MAX - max(0 , x%10))/10;
            int comp2 = (INT_MIN - min(0 , x%10))/10;
            if(res > comp1 || res < comp2) return 0;
            res = res*10 + (x%10);
            x/=10;
        }
        return res;
    }
};
