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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back({root->val});

        while(!que.empty()) {
            int n = que.size();
            temp.clear();

            while(n--) {
                TreeNode* node = que.front();
                que.pop();

                if(node->left) {
                    temp.push_back(node->left->val);
                    que.push(node->left);
                }
                if(node->right) {
                    temp.push_back(node->right->val);
                    que.push(node->right);
                }

            }

            if(!temp.empty())
                result.push_back(temp);
        }

        return result;
    }
};
