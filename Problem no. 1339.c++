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
    long total_sum = 0;
    long max_pro = 0;
    long mod = 1e9+7;

    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int left  = solve(root->left);
        int right = solve(root->right);

        int sub_tree_sum = left + right + root->val;
        int rem_sum = total_sum - sub_tree_sum;

        max_pro = max(max_pro, (long)rem_sum * sub_tree_sum);
    
        return sub_tree_sum;
    }

    int maxProduct(TreeNode* root) {        
        total_sum = solve(root);
        
        solve(root);

        return max_pro % mod;
    }
};
