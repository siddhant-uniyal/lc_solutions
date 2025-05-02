class Solution {
public:
    string pushDominoes(string s) {
        int i = 0; //position of . or R
        int n = s.size();
        while(i < n){
            if(s[i] == 'L'){ //only allow start from . or R
                ++i;
                continue;
            }
            int j = i + 1;
            while(j < n and s[j] == '.') ++j;
            if(s[i] == '.'){
                if(j == n) break; //its just ......
                if(s[j] == 'L'){ //its ....L , so make all left
                    for(int k = j - 1 ; k >= i ; --k) s[k] = 'L';
                }
                i = j + (s[j] == 'L'); //if it was ...R , start from this R now
            }
            else{
                if(j == n or s[j] == 'R'){ //its R....(end) or R...R , make all R
                    for(int k = i + 1 ; k <= min(j,n-1) ; ++k) s[k] = 'R';
                    i = j;
                }
                else{
                    //its R...L , apply logic
                    int mid = (i + j)/2;
                    for(int k = i ; k <= j ; ++k){
                        s[k] = k > mid ? 'L' : 'R';
                    }
                    if((j - i + 1)&1) s[mid] = '.';
                    i = j + 1;
                }
            }
        }
        return s;
    }
};