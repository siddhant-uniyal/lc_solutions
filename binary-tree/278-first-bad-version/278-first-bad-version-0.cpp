// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1 , r = n + 1;
        while(l < r){
            long m = l + ((r-l)>>1);
            if(isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};