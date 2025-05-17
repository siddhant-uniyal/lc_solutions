class Solution {
public:
    int reachNumber(int target) {
        /*
        WRONG:
            +ve and -ve target : same answer
            x moves : 1,2,3..x
            some +ve , some -ve
            so its : x*(x + 1)/2 - 2*(neg moves)
            neg moves sum can be anything from 1 to x*(x+1)/2
            so just check if possible with binary search
        */
        target = abs(target);
        // int l = 1 , r = target + 1;
        // while(l < r){
        //     int m = l + ((r-l)>>1);
        //     int neg2 = m*(m + 1)/2 - target;
        //     bool even = !(neg2&1);
        //     bool inRange = (neg2 >= 2) && (neg2 <= m*(m + 1));
        //     if(even && inRange) r = m;
        //     else l = m + 1;
        // }
        // return l;
        for(int i = 1 ; i <= 2*target ; ++i){
            int m = i;
            int neg2 = (m*(m + 1)/2) - target;
            if(neg2 == 0) return i;
            bool even = !(neg2&1);
            bool inRange = (neg2 >= 2) && (neg2 <= m*(m + 1));
            if(even&&inRange) return i;
        }
        return -1;
    }
};