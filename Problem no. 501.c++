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
    unordered_map<int, int> mp;
    
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            mp[root->val]++;
            inorder(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        vector<int> result;
        int max_freq = 0;

        for(auto it : mp)
        {
            if(it.second > max_freq)
            {
                max_freq = it.second;
                result = {};
                result.push_back(it.first);
            }

            else if(it.second == max_freq)
            {
                result.push_back(it.first);
            }
        }

        return result;
    }
};
