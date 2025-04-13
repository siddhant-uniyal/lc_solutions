class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int>occ(26);
        for(char &c : s){
            ++occ[c - 'a'];
        }
        string data = "";
        char odd = 'X';
        for(int i = 0 ; i < 26 ; ++i){
            if(!occ[i]) continue;
            int f = (occ[i] - (occ[i]&1))/2;
            data += string(f , 'a' + i);
            if(occ[i]&1) odd = 'a' + i;
        }
        int sz = data.size();
        string ans = "";
        bool few = false;
        // cout << data << " " << sz << endl;
        --k;
        for(int i = 0 ; i < k ; ++i){
            int j = sz - 2;
            while(j >= 0 and data[j] >= data[j + 1]) --j;
            if(j < 0){
                few = true;
                break;
            }
            int k = sz - 1;
            while(k > j and data[k] <= data[j]) --k;
            swap(data[j] , data[k]);
            reverse(data.begin() + (j + 1) , data.end());
        }
        if(few) return "";
        ans = data;
        if(odd != 'X') ans += odd;
        reverse(data.begin() , data.end());
        return ans + data;
    }
};