class Solution {
public:
    string convert(string s, int rows) {

        if(rows == 1){
            return s;
        }

        int offset = 0;
        int mainJump = 2*(rows-1);
        int midJump = 0;
        int index = 0;
        int n = s.length();

        string ans(n , ' ');

        for(int iter = 0 ; iter < rows ; ++iter){

            int prt = 0;
            for(int i = offset ; i < n ;){
                ans[index] = s[i];

                if (iter == 0 or (iter != rows - 1 and !prt)) {
                    i += mainJump;
                } else {
                    i += midJump;
                }

                prt^=1;
                ++index;
            }
            mainJump -= 2;
            midJump += 2;
            ++offset;
        }

        return ans;

    }
};