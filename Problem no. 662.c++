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
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , int>> que;
        que.push({root , 0});
        int result = 0;

        while(!que.empty()) {
            int n = que.size();
            int left = que.front().second;
            int right = que.back().second;

            result = max(result , right-left+1);

            while(n--) {
                TreeNode* temp = que.front().first;
                ll idx = que.front().second;

                if(temp && temp->left) {
                    que.push({temp->left , 2*idx+1});
                }
                
                if(temp && temp->right) {
                    que.push({temp->right , 2*idx+2});
                }
                
                que.pop();
            }
        }

        return result;
    }
};
