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

    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);

        int sum1 = left + right + root->val;
        int sum2 = max(left, right) + root->val;
        int sum3 = root->val;

        result =  max({result, sum1, sum2, sum3});

        return max({sum2 , sum3});
    }

    int maxPathSum(TreeNode* root) {
        result = INT_MIN;

        solve(root);

        return result;
    }
};
