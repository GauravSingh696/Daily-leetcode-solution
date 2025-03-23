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
    void make_graph(unordered_map<int, vector<int>> &adj, int parent, TreeNode* curr) {
        if(!curr)
            return;
        
        if(parent != -1)
            adj[curr->val].push_back(parent);
        
        if(curr->left)
            adj[curr->val].push_back(curr->left->val);
        
        if(curr->right)
            adj[curr->val].push_back(curr->right->val);
        
        make_graph(adj, curr->val, curr->left);
        make_graph(adj, curr->val, curr->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;

        make_graph(adj, -1, root);

        unordered_set<int> visited;
        queue<int> que;
        int result = 0;

        visited.insert(start);
        que.push(start);

        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                int curr = que.front();
                que.pop();

                for(auto &it : adj[curr]) {
                    if(visited.find(it) == visited.end()) {
                        visited.insert(it);
                        que.push(it);
                    }
                }
            }

            result++;
        }

        return --result;
    }
};
