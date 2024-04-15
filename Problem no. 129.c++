//  15-04-2024

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
    int solve(TreeNode *root, int sum)
    {
        if(root==NULL)
            return 0;

        sum = sum*10 + root->val;

        if(root->left==NULL && root->right==NULL)
        {
            return sum;
        }

        int left = solve(root->left, sum);
        int right = solve(root->right, sum);

        return left+right;
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;
        return solve(root, sum);
    }
};
