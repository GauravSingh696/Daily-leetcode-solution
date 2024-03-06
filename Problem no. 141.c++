//  06-03-2024

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowPtr=head;
        ListNode* fastPtr=head;

        while(slowPtr!=NULL && fastPtr!=NULL && fastPtr->next!=NULL)
        {
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;

            if(slowPtr==fastPtr)
                return true;
        }
        return false;
    }
};
