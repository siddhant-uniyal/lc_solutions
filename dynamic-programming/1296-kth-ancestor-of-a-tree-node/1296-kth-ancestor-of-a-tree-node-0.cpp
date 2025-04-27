class TreeAncestor {
public:
    /*
    standard binary lifting
    jump[i][j] : (1<<j)th ancestor of i
    base case :
    jump[i][0] = parent[i]
    then , 
    jump[i][j] = jump[jump[i][j-1]][j-1] 
    eg : 2nd ancestor of i ? its just the 1st ancestor of 1st ancestor of i
    8th ? 4th ancestor of 4th ancestor of i
    */
    vector<vector<int>>jump;
    int lg;
    TreeAncestor(int n , vector<int>& parent) {
        int lg = 0;
        while((1<<(lg)) <= n) ++lg;
        this->lg = lg;
        jump.resize(n , vector<int>(lg , -1));
        for(int i = 0 ; i < n ; ++i){
            //base case
            jump[i][0] = parent[i];
        }
        for(int j = 1 ; j < lg ; ++j){
            for(int i = 0 ; i < n ; ++i){
                if(jump[i][j - 1] != -1){
                    jump[i][j] = jump[jump[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        /*
        k = 8 + 4 + 1
        jump[ jump[ jump[node][1] ][4] ][8]
        */
        for(int j = 0 ; j < lg ; ++j){
            if(k&(1<<j)){
                node = jump[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */