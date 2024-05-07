// 07-05-2024

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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while(curr)
        {
            int value = curr->val*2;

            if(value<10)
            {
                curr->val = value;
            }

            else if(prev != NULL)
            {
                prev->val += 1;
                curr->val = value%10;
            }

            else
            {
                ListNode *newnode = new ListNode(1);
                newnode->next = curr;
                curr->val = value%10;
                head = newnode;
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
