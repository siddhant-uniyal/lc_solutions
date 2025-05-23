class Solution {
public:
    int reverse(int x) {
        bool isNeg = (x<0);
        x = abs(x);
        int res = 0;
        while(x){
            if(res > ((INT_MAX - (x&10))/10)) return 0;
            res = res*10 + (x%10);
            x/=10;
        }
        return (isNeg ? -1 : 1) * res;
    }
};
