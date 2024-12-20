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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while(!que.empty()) {
            int n = que.size();
            vector<int> vec;
            vector<TreeNode*> node;
            int k = n;

            while(n--) {
                TreeNode* temp = que.front();
                
                if(level%2 == 0) {
                    node.push_back(temp);
                    if(temp->left) {
                        que.push(temp->left);
                        vec.push_back(temp->left->val);
                    }
                    if(temp->right) {
                        que.push(temp->right);
                        vec.push_back(temp->right->val);
                    }

                    que.pop();
                }
                else {
                    if(temp->left) {
                        que.push(temp->left);
                    }
                    if(temp->right) {
                        que.push(temp->right);
                    }

                    que.pop();
                }
            }

            if(!vec.empty()) {
                int size = vec.size()-1;

                for(auto it : node) {
                    if(it->left) {
                        it->left->val = vec[size--];
                    }

                    if(it->right) {
                        it->right->val = vec[size--];
                    }
                }
            }

            level++;
        }

        return root;
    }
};
