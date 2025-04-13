class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int>occ(26);
        for(char &c : s) ++occ[c - 'a'];
        string data = "";
        for(int i = 0 ; i < 26 ; ++i){
            if(!occ[i]) continue;
            int f = (occ[i] - (occ[i]&1))/2;
            data += string(f , 'a' + i);
            occ[i] = (occ[i]&1);
        }
        char odd = 'X';
        for(int i = 0 ; i < 26 ; ++i){
            if(occ[i]){
                odd = 'a' + i;
                break;
            }
        }
        int sz = data.size();
        bool much = false;
        string ans = "";
        --k;
        for(int i = 0 ; i < k; ++i){
            // cout << data << endl;
            //next permutation
            int found = false;
            for(int j = sz - 1 ; j >= 1 ; --j){
                if(data[j - 1] <= data[j]){
                    int mn = 'z' + 1 , ind = -1;
                    for(int k = sz - 1 ; k >= j ; --k){
                        if(data[k] < mn and data[k] > data[j-1]){
                            mn = data[k];
                            ind = k;
                        }
                    }
                    swap(data[j - 1] , data[ind]);
                    reverse(data.begin() + j , data.end());
                    found = true;
                    break;
                }
            }
            if(!found){
                much = true;
                break;
            }
        }
        if(much){
            ans = "";
        }
        else{
            // cout << data << endl;
            ans = data;
            if(odd != 'X') ans += odd;
            reverse(data.begin() , data.end());
            ans += data;
        }
        return ans;
    }
};