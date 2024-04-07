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
    int sum=0;

    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;

        else
        {
            if(isleftLeavesNode(root->left))
                sum += root->left->val;
            
            solve(root->left);
            solve(root->right);
        }
    }

    bool isleftLeavesNode(TreeNode *root)
    {
        if(root==NULL)
            return false;
        
        else if(root->left==NULL && root->right==NULL)
            return true;

        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        solve(root);
        return sum;
    }
};
