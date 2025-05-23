class Solution {
public:
    int myAtoi(string s) {
        int ptr = 0 , n = s.size();
        int res = 0;
        while(ptr < n && s[ptr] == ' ') ++ptr;
        int sign = 1;
        if(ptr < n && (s[ptr] == '-' || s[ptr] == '+')){
            sign = (s[ptr] == '-' ? -1 : 1);
            ++ptr;
        }
        while(ptr < n){
            if(s[ptr] < '0' || s[ptr] > '9') break;
            if(s[ptr] == '0' && res == 0){
                ++ptr;
                continue;
            }
            int digit = (s[ptr] - '0') * sign;
            int comp1 = (INT_MAX - max(0 , digit))/10;
            int comp2 = (INT_MIN - min(0 , digit))/10;
            if(res > comp1){
                res = INT_MAX;
            }
            else if(res < comp2){
                res = INT_MIN;
            }
            else res = res*10 + digit;
            ++ptr;
        }
        return res;
    }
};