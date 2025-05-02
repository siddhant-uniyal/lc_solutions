class Solution {
public:
    string pushDominoes(string s) {
        int i = -1; //i = pos of R or .
        int n = s.size();
        while(i < n){
            /*
            either its .....L
            or R.....L 

            if its ....R or R...R , just jump to that

            if its R... , consider it
            if its .... , skip
            */
            int j = i + 1;
            while(j < n and s[j] == '.') ++j;
            if(j < n and s[j] == 'R'){
                i = j;
                continue;
            }
            if(j == n and (i < 0 or (i >= 0 and s[i] == '.'))) break;
            //this is a valid pair. now it can be a prefix L or a suffix R or a regular R..L pair
            // cout << i << " " << j << endl;
            if(i == -1){
                for(int k = 0 ; k < j ; ++k) s[k] = 'L';
            }
            else if(j == n){
                for(int k = i + 1 ; k < n ; ++k) s[k] = 'R';
            }
            else{
                int mid = (i + j)/2;
                for(int k = i ; k <= j ; ++k){
                    if(k <= mid) s[k] = s[i] == 'R' ? 'R' : 'L';
                    else s[k] = 'L';
                }
                if(s[i] == 'R' and ((i-j+1)&1)) s[mid] = '.';
            }
            i = j + 1;
        }
        return s;
    }
};