/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    void preorder(TreeNode* cloned, TreeNode* tar)
    {
        if(cloned)
        {
            if(cloned->val == tar->val)
            {
                res = cloned;
                return;
            }
            preorder(cloned->left, tar);
            preorder(cloned->right, tar);
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        preorder(cloned,target);

        return res;
    }
};
