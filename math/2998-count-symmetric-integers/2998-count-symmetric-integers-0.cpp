class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        int l1 = max(10 , low);
        int r1 = min(high , 99);

        int l2 = max(1000 , low);
        int r2 = min(high , 9999);

        if(l1 <= r1){
            int msb1 = l1/10;
            int msb2 = r1/10;
            for(int i = msb1 ; i <= msb2 ; ++i){
                int gen = i*11;
                ans += (gen >= l1 and gen <= r1);
            }
        }

        if(l2 <= r2){
            int msb1 = l2/100;
            int msb2 = r2/100;
            for(int i = msb1 ; i <= msb2 ; ++i){
                int tsum = (i/10) + (i%10);
                for(int j = tsum ; j >= 0 ; --j){
                    if(j >= 0 and j <= 9 and tsum - j >= 0 and tsum - j <= 9){
                    int gen = i*100 + (j*10) + (tsum - j);
                    ans += (gen >= l2 and gen <= r2);
                    }
                }
            }
        }
        return ans;
    }
};