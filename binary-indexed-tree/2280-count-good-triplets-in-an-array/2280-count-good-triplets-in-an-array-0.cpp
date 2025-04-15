class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        /*
        for each j
        in nums1 , check to its left and right
        same for nums2
        intersection in left * intersection in right
        */
        /*
        4 : 0 , 0
        0 : 1 , 2
        1 : 2 , 1
        3 : 3 , 4
        2 : 4 , 3

        2 : 0 , 2
        0 : 1 , 0
        1 : 2 , 1
        3 : 3 , 3

        so basically
        cnt of lesser indices in num2 * cnt of greater indices in num2
        */
        int n = nums1.size();
        vector<int>occ1(n) , occ2(n);
        for(int i = 0 ; i < n ; ++i){
            occ1[nums1[i]] = i;
        }
        for(int i = 0 ; i < n ; ++i){
            int ind = occ1[nums2[i]];
            occ2[ind] = i;
        }

        long long ans = 0LL;
        for(int i = 1 ; i < n - 1 ; ++i){
            // cout << nums1[i] << ": " << i << " , " << occ2[occ1[nums1[i]]] << endl;
            long long cnt1 = 0 , cnt2 = 0;
            for(int j = i - 1 ; j >= 0 ; --j){
                cnt1 += (occ2[j] < i);
            }
            for(int j = i + 1 ; j < n ; ++j){
                cnt2 += (occ2[j] > i);
            }
            ans += cnt1 * cnt2;
        }
        return ans;
    }
};