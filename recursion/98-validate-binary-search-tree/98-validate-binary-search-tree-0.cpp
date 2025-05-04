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
    bool isValidBST(TreeNode* root) {
        auto dfs = [&](TreeNode *root , long l , long r , auto &&self) -> bool{
            if(root == nullptr) return true;
            long val = 1L*root->val;
            if(val < l or val > r) return false;
            return self(root->left , l , val - 1L , self) and self(root->right , val + 1L , r , self);
        };
        return dfs(root , INT_MIN , INT_MAX , dfs);
    }
};