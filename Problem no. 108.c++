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
    TreeNode* bst(vector<int> nums , int left , int right)
    {
        if(left>right)
            return NULL;
        
        int midPoint=left+(right-left)/2;
        TreeNode* newnode = new TreeNode(nums[midPoint]);
        newnode->left=bst(nums, left, midPoint-1);
        newnode->right=bst(nums, midPoint+1, right);
        return newnode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;

        return bst(nums, 0, nums.size()-1);
    }

};
