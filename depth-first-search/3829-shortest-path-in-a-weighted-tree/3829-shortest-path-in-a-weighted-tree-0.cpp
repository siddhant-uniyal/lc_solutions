class SegTree{
private:
    vector<int>seg;
    vector<int>lazy;
    vector<pair<int,int>>data;
    int n;
public:
    SegTree(vector<pair<int,int>> &data) {
        n = data.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        this->data = data;
        build(0 , n-1 , 0);
    }
    void resolvePending(int l , int r , int ind , int val){
        seg[ind] += (r-l+1)*val;
        if(l != r){
            lazy[2*ind + 1] += val;
            lazy[2*ind + 2] += val;
        }
        lazy[ind] = 0;
    }
    void build(int l , int r , int ind){
        if(l == r){
            seg[ind] = data[l].second;
            return;
        }
        int m = l + ((r-l)>>1);
        build(l , m , 2*ind + 1);
        build(m + 1 , r , 2*ind + 2);
        seg[ind] = min(seg[2*ind + 1] , seg[2*ind + 2]); //doesnt matter , ranges of size > 1 wont be queried
    }
    void update(int l , int r , int ql , int qr , int val , int ind){
        resolvePending(l , r , ind , lazy[ind]);
        if(l >= ql and r <= qr){
            resolvePending(l , r , ind , val);
            return;
        }
        if(l > qr or r < ql) return;
        int m = l + ((r-l)>>1);
        update(l , m , ql , qr , val , 2*ind + 1);
        update(m + 1 , r , ql , qr , val , 2*ind + 2);
        seg[ind] = min(seg[2*ind + 1] , seg[2*ind + 2]);
    }
    int query(int l , int r , int ql , int qr , int ind){
        resolvePending(l , r , ind , lazy[ind]);
        if(l >= ql and r <= qr) return seg[ind];
        if(r < ql or l > qr) return INT_MAX;
        int m = l + ((r-l)>>1);
        return min(query(l , m , ql , qr , 2*ind + 1) , query(m + 1 , r , ql , qr , 2*ind + 2));
    }
    void update(int l , int r , int val){
        update(0 , n - 1 , l , r , val , 0);
    }
    int query(int l , int r){
        return query(0 , n - 1 , l , r , 0);
    }
};
class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            --e[0] , --e[1];
            adj[e[0]].emplace_back(e[1] , e[2]);
            adj[e[1]].emplace_back(e[0] , e[2]);
        }
        vector<pair<int,int>>data; //used for build of seg tree
        vector<int>node2Ind(n); //for proper indexing 
        vector<int>node2Sz(n); //subtree size , for updating the range in seg tree
        vector<pair<int,int>>node2Par(n); //parent and edge weight between node and parent for each node
        int index = 0;
        auto flatten = [&](int src , int par , int cost , auto &&self) -> int{
            node2Ind[src] = index++;
            data.emplace_back(src , cost);
            int subtreeSz = 1;
            for(auto &[nxt,wt] : adj[src]){
                if(!(nxt^par)) continue;
                subtreeSz += self(nxt , src , cost + wt , self);
                node2Par[nxt] = {src , wt};
            }
            node2Sz[src] = subtreeSz;
            return subtreeSz;
            /*
            why sz = 0 , return max(sz , 1) was wrong

                 2
               4 5 6
               7

               7 -> 0
               4 -> 1
               5 -> 1
               6 -> 1
               2 -> 3 , but its 4 
               so just scrap it entirely and do 
               sz = 1
               return sz
               or do
               sz = 0
               return sz + 1
               +1 handles ignoring the current node

               but then
               node2sz = subtreesz : offset , current node not included , no -1 needed ; subtreesz + 1 : actual size including current node , -1 needed
            */
        };
        flatten(0 , -1 , 0 , flatten);
        SegTree lz = SegTree(data);
        vector<int>ans;
        for(auto &q : queries){
            if(q[0] == 2){
                --q[1];
                int IND = node2Ind[q[1]];
                ans.push_back(lz.query(IND , IND));
            }
            else{
                --q[1] , --q[2];
                int child = (node2Par[q[1]].first == q[2]) ? q[1] : q[2];
                int sz = node2Sz[child];
                int delta = q[3] - node2Par[child].second;
                int IND = node2Ind[child];
                lz.update(IND , IND + sz - 1 , delta);
                node2Par[child].second = q[3];
            }
        }
        return ans;
    }
};