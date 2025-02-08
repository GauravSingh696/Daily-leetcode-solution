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
    vector<vector<int>> result;

    void solve(TreeNode* root, int tar, int sum, vector<int>temp) {
        if(!root)
            return ;
        
        sum += root->val;
        temp.push_back(root->val);

        solve(root->left , tar, sum, temp);
        solve(root->right, tar, sum, temp);

        if(!root->left && !root->right && sum == tar) {
            result.push_back(temp);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;

        solve(root, targetSum, sum, temp);

        return result;
    }
};
