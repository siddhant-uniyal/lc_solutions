int d[5] = {-1,0,1,0,-1};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        queue<tuple<int,int,int>>bfs;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(board[i][j] == word[0]){
                    bfs.emplace(i*m + j , 0 , -1);
                }
            }
        }
        int wsz = word.size();
        for(int len = 0 ; len < wsz ; ++len){
            int qsz = bfs.size();
            while(qsz--){
                auto [src , index , par] = bfs.front();
                bfs.pop();
                if(index == wsz - 1) return true;
                int x = src/m , y = src%m;
                for(int k = 0 ; k < 4 ; ++k){
                    int X = x + d[k] , Y = y + d[k + 1];
                    if(min(X , Y) >= 0 and X < n and Y < m and board[X][Y] == word[index + 1] and X*m + Y != par){
                        bfs.emplace(X*m + Y , index + 1 , src);
                    }
                }
            }
        }
        return false;
    }
};