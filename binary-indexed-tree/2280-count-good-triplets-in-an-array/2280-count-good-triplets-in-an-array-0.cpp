#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>occ1(n);
        for(int i = 0 ; i < n ; ++i){
            occ1[nums1[i]] = i;
        }
        //occ2[i] : index of nums1[i] in nums2.
        long long ans = 0LL;
        ordered_set st;
        for(int i = 0 ; i < n ; ++i){
            int ind = occ1[nums2[i]];
            long long less = st.order_of_key(ind);
            long long more = (n - ind - 1) - ((int)st.size() - less);
            ans += less * more;
            st.insert(ind);
        }
        return ans;
    }
};