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
    vector<tuple<int, int, int>> vec;

    void solve(TreeNode* root, int level, int col) {
        if(!root)
            return;

        vec.push_back({col, level, root->val});
        
        solve(root->left, level+1, col-1);
        solve(root->right, level+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int level = 0, col = 0;

        solve(root, level, col);

        sort(vec.begin(), vec.end());

        vector<vector<int>> res;
        map<int, vector<int>> colMap;

        for (auto [col, row, val] : vec) {
            colMap[col].push_back(val);
        }

        for (auto& [col, vals] : colMap) {
            res.push_back(vals);
        }

        return res;
    }
};
