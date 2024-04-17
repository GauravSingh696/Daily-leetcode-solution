// 17-04-2024

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

//  using dfs approach 1.
class Solution {
public:
    string result="";

    void dfs(TreeNode *root, string curr)
    {
        if(root==NULL)
            return;

        curr = char(root->val + 'a') + curr;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(result=="" || result > curr)
                result = curr;
            
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        
        return result;
    }
};



// using bfs approach 2.
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result="";
        queue<pair<TreeNode*, string>> que;

        que.push({root, string(1, char(root->val+'a'))});

        while(!que.empty())
        {
            auto[node, curr] = que.front();
            que.pop();

            if(node->left==NULL && node->right==NULL)
            {
                if(result=="" || result > curr)
                    result = curr;
            }

            if(node->left)
            {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }

            if(node->right)
            {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
        }

        return result;
    }
};
