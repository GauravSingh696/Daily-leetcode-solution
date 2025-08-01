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
    int sum = 0;
public:
    void solve(TreeNode* root) {
        if(!root)
            return ;
        
        solve(root->right);

        sum+= root->val;
        root->val = sum;
        
        solve(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        solve(root);

        return root;
    }
};
