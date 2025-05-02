class Solution {
public:
    string pushDominoes(string s) {
        int i = -1; //i = pos of R
        int n = s.size();
        while(i < n){
            int x = i + 1;
            int foundL = -1;
            while(x < n and s[x] != 'R'){
                if(s[x] == 'L') foundL = x;
                ++x;
            }
            //special case : x = n. this is ok
            if(x == n and foundL == -1) foundL = n;
            if(foundL != -1){
                //this is a valid pair. now it can be a prefix L or a suffix R or a regular R..L pair
                cout << i << " " << foundL << endl;
                if(i == -1){
                    for(int j = 0 ; j < foundL ; ++j) s[j] = 'L';
                }
                else if(foundL == n){
                    for(int j = i + 1 ; j < n ; ++j) s[j] = 'R';
                }
                else{
                    int mid = (i + foundL)/2;
                    for(int j = i ; j <= foundL ; ++j){
                        if(j <= mid) s[j] = 'R';
                        else s[j] = 'L';
                    }
                    if((i-foundL+1)&1) s[mid] = '.';
                }
            }
            i = x;
        }
        return s;
    }
};