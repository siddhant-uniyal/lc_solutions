class Solution {
public:
    int minDominoRotations(vector<int>& t , vector<int>& b) {
        int n = t.size();
        /*
        //try checking all values , condition being that it has to occur in every single domino's top or bottom
        //then , 2 ways : make top equal or bottom. if top != value , then ++top , same for bottom
        for(int i = 1 ; i <= 6 ; ++i){
            int makeT = 0 , makeB = 0;
            for(int j = 0 ; j < n ; ++j){
                int x = t[j] , y = b[j];
                if(x != i and y != i){
                    makeT = n + 1 , makeB = n + 1;
                    break;
                }
                makeT += (x != i);
                makeB += (y != i);
            }
            ans = min({ans , makeT , makeB});
        }
        return ans == n + 1 ? -1 : ans;

        //optimized : only check for the values t[0] and b[0]. since all values have to eventually be the same, they must all either be t[0] or b[0].
        */
        int data[2][2] = {0}; //data[i][j] : make all values in jth row equal to i == 0 ? t[0] : b[0]
        for(int i = 0 ; i < n ; ++i){
            data[0][0] += (t[i] != t[0]);
            data[0][1] += (b[i] != t[0]);
            data[1][0] += (t[i] != b[0]);
            data[1][1] += (b[i] != b[0]);
            if(t[i] != t[0] and b[i] != t[0]){
                data[0][0] = n + 1;
                data[0][1] = n + 1;
            }
            if(t[i] != b[0] and b[i] != b[0]){
                data[1][0] = n + 1;
                data[1][1] = n + 1;
            }
        }
        int ans = min({data[0][0] , data[0][1] , data[1][0] , data[1][1]});
        return ans >= n + 1 ? -1 : ans;
    }
};