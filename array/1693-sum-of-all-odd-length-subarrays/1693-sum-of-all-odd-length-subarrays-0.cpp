class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int odd = 0 , even = 0 , ans = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; ++i){
            int oeven = even;
            int olens = (i + 2)/2;
            even = odd + arr[i]*(i + 1 - olens);
            odd = oeven + arr[i]*(olens);
            ans += odd;
        }
        return ans;
    }
};