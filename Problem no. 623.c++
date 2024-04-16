// 16-04-2024

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
    TreeNode *add(TreeNode *root, int val, int depth, int curr)
    {
        if(root==NULL)
            return NULL;
        
        else if (curr == depth-1)
        {
            TreeNode *leftnode = root->left;
            TreeNode *rightnode = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftnode;
            root->right->right = rightnode;

            return root;
        }

        root->left = add(root->left, val, depth, curr+1);
        root->right = add(root->right, val, depth, curr+1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode *newnode = new TreeNode(val);
            newnode->left = root;

            return newnode;
        }

        int curr=1;

        return add(root, val, depth, curr);
    }
};
