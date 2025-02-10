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
    string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &vec) {
        if(!root)
            return "N";
        
        string str = to_string(root->val) + "," + solve(root->left, mp, vec) + "," + solve(root->right, mp, vec);

        if(mp[str] == 1)
            vec.push_back(root);
        
        mp[str]++;
        
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> vec;

        solve(root, mp, vec);

        return vec;
    }
};
