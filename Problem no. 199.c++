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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = NULL;
            int size = que.size();
            

            while(size--) {
                node = que.front();

                if(node->left)
                    que.push(node->left);
            
                if(node->right)
                    que.push(node->right);

                que.pop();
                    
            }

            result.push_back(node->val);
        }

        return result;
    }
};
