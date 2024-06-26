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
    void inorder(TreeNode *root, vector<int> &v)
    {
        if(root)
        {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;

        inorder(root, v);

        sort(v.begin(), v.end());

        int n = v.size();
        int i=0, j=n-1;

        while(i<j)
        {
            if(v[i] + v[j] == k)
                return true;
            
            else if(v[i] + v[j] > k)
                j--;
            
            else
                i++;
        }

        return false;
    }
};
