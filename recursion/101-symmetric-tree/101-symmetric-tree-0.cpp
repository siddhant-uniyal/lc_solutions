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
    bool isSymmetric(TreeNode* root) {
        auto dfs = [&](TreeNode *root1 , TreeNode *root2 , auto &&self) -> bool{
            if(root1 == nullptr and root2 == nullptr) return true;
            if(root1 == nullptr or root2 == nullptr) return false;
            if(root1->val != root2->val) return false;
            return self(root1->left , root2->right , self) and self(root1->right , root2->left , self);
        };
        return dfs(root->left , root->right , dfs);
    }
};