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


// approach 1...

class Solution {
public:
    int count=0;
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            count++;
            inorder(root->right);
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        inorder(root);
        return count;

    }
};



// appoarch 2...

class Solution {
public:
    int get_left(TreeNode* root) {
        int height = 1;

        while(root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int get_right(TreeNode* root) {
        int height = 1;

        while(root) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int left  = get_left(root->left);
        int right = get_right(root->right);

        if(left == right)
            return pow(2, left) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
