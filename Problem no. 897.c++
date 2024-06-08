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
    void inorder(TreeNode* root,vector<int>& in)
    {
        if(root)
        {
            inorder(root->left,in);
            in.push_back(root->val);
            inorder(root->right,in);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);

        TreeNode *head=new TreeNode();
        TreeNode *temp=head;
        head->left=NULL;
        for(auto i:in)
        {
            TreeNode *c=new TreeNode(i);
            c->left=NULL;
            temp->right=c;
            temp=temp->right;
        }
        return head->right;
    }
};
