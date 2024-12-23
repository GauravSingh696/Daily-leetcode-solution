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
    int minswap(vector<int> v) {
        vector<int> temp(v.begin(),v.end());
        sort(temp.begin(), temp.end());

        unordered_map<int,int> mp;
        for(int i=0 ; i<v.size() ; i++) {
            mp[temp[i]]=i;
        }

        int cnt=0;

        for(int i=0; i<v.size();){
            int ind = mp[v[i]];
            if(ind == i){
                i++;
            }
            else{
                int temp = v[i];
                v[i] = v[ind];
                v[ind] = temp;
                cnt++;
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--) {
                TreeNode *it=q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left) q.push(it->left);

                if(it->right) q.push(it->right);
            }
            ans+=minswap(temp);
        }
        return ans;
    }
};
