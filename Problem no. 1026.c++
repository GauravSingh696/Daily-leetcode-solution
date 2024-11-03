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
    int result;

    void find_max_diff(TreeNode* &root, TreeNode* &child) {
        if(!root || !child)
            return ;
        
        result = max(result , abs(root->val - child->val));

        find_max_diff(root, child->left);
        find_max_diff(root, child->right);
    }

    void solve(TreeNode* &root) {
        if(!root)
            return ;
        
        find_max_diff(root , root->left);
        find_max_diff(root , root->right);

        solve(root->left);
        solve(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        result = -1;

        solve(root);

        return result;
    }
};
