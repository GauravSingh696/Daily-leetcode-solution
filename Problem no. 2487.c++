// 06-05-2024

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseNode(ListNode *root)
    {
        if(root==NULL || root->next==NULL)
            return root;
        
        ListNode *last = reverseNode(root->next);

        root->next->next = root;
        root->next = NULL;

        return last;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseNode(head);

        int maxNode = -1;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr)
        {
            maxNode = max(maxNode, curr->val);

            if(curr->val < maxNode)
            {
                prev->next = curr->next;
                ListNode *temp = curr;
                curr = curr->next;
                delete(temp);
            }

            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return reverseNode(head);
        
    }
};
