/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx = 0;
        auto dfs = [&](TreeNode *root , int depth , auto &&self) -> pair<TreeNode* , int> {
            if(root == nullptr){
                return make_pair(nullptr , depth - 1);
            }
            mx = max(mx , depth);
            auto l = self(root->left , depth + 1 , self);
            auto r = self(root->right , depth + 1 , self);
            if(l.second == r.second and l.second == mx){
                return make_pair(root , mx);
            }
            else return l.second > r.second ? l : r;
        };
        return dfs(root , 0 , dfs).first;
    }
};