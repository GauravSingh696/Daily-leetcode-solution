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
    TreeNode* solve(vector<int>& inorder, vector<int>& post, int start, int end, int &idx) {
        if(start > end) 
            return NULL;
        
        int i = start;
        int val = post[idx];

        for(;i<=end;i++) {
            if(inorder[i] == val)
                break;
        }

        TreeNode* root = new TreeNode(val);
        idx--;

        root->right = solve(inorder, post, i+1, end, idx);
        root->left  = solve(inorder, post, start, i-1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size()-1;
        return solve(inorder, postorder, 0, n, n);
    }
};
