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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        int add = 0;
        int carry = 0;

        ListNode *result = new ListNode(0);
        ListNode *curr = result;

        while(h1 && h2)
        {
            add = h1->val + h2->val;

            add += carry;
            carry = 0;
            
            if(add > 9)
            {
                carry = add/10;
                add = add%10;
            }

            curr->next = new ListNode(add);
            curr = curr->next;

            h1 = h1->next;
            h2 = h2->next;
        }

        if(!h1 && !h2)
        {
            if(carry > 0)
            {
                curr->next = new ListNode(carry);
                curr = curr->next;
            }
            return result->next;
        }

        while(h1)
        {
            add = carry + h1->val;
            carry = 0;

            if(add > 9)
            {
                carry = add/10;
                add = add%10;
            }

            curr->next = new ListNode(add);
            curr = curr->next;

            h1 = h1->next;
        }

        while(h2)
        {
            add = carry + h2->val;
            carry = 0;

            if(add > 9)
            {
                carry = add/10;
                add = add%10;
            }

            curr->next = new ListNode(add);
            curr = curr->next;

            h2 = h2->next;
        }

        if(carry > 0)
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }

        return result->next;
    }
};
