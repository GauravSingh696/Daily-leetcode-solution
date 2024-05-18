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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        vector<double> result;

        while(!que.empty())
        {
            double sum = 0;
            int n = que.size();
            double count = n;

            for(int i=0;i<n;i++)
            {
                TreeNode *temp = que.front();
                que.pop();

                if(temp->left)
                   que.push(temp->left);

                if(temp->right)
                    que.push(temp->right); 
                
                sum += temp->val;
            }

            result.push_back(sum/n);

        }

        return result;
    }
};
