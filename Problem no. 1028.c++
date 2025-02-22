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
    int n;

    TreeNode* solve(int depth, int &i, string &str) {
        if(i>=n)
            return NULL;
        
        int j=i;

        while(j<n && str[j]=='-')
            j++;
        
        int dash = j-i;
        
        if(depth != dash)
            return NULL;
        
        int num = 0;
        i += dash;

        while(i<n && str[i]!='-') {
            num = num*10 + str[i]-'0';
            i++;
        }

        TreeNode* root = new TreeNode(num);

        root->left  = solve(depth+1, i, str);
        root->right = solve(depth+1, i, str);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int depth = 0 , idx = 0;

        return solve(depth, idx, traversal);
    }
};
