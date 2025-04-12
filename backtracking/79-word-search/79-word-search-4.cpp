int d[5] = {-1,0,1,0,-1};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        int sz = word.size();
        auto dfs = [&](int x , int y , int index , auto &&self) -> bool{
            if(index == sz - 1) return true;
            bool to_return = false;
            board[x][y]^=(1<<7);
            for(int i = 0 ; i < 4 ; ++i){
                int X = x + d[i] , Y = y + d[i + 1];
                if(min(X , Y) >= 0 and X < n and Y < m and board[X][Y] == word[index + 1]){
                    to_return |= self(X , Y , index + 1 , self);
                }
            }
            board[x][y]^=(1<<7);
            return to_return;
        };
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(board[i][j] == word[0] and dfs(i , j , 0 , dfs)) return true;
            }
        }
        return false;
    }
};