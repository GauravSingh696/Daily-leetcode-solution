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
    vector<long long int> vec;
public:
    void inorder(TreeNode *root, long long int &sum)
    {
        if(root)
        {
            inorder(root->left, sum);
            sum += root->val;
            vec.push_back(root->val);
            inorder(root->right, sum);
        }
    }

    void solve(TreeNode* root, stack<long long int> &st)
    {
        if(root)
        {
            solve(root->left, st);
            root->val = st.top();
            st.pop();
            solve(root->right, st);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        long long int sum = 0;

        inorder(root, sum);

        int n = vec.size();

        vector<long long int> temp(vec);

        vec[0] = sum;

        for(int i=1;i<n;i++)
        {
            sum -= temp[i-1];
            vec[i] = sum;
        }

        stack<long long int> st;

        for(int i=n-1;i>=0;i--)
        {
            st.push(vec[i]);
        }

        solve(root, st);

        return root;
    }
};
