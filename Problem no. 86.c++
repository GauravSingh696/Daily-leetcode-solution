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
    ListNode* partition(ListNode* head, int x) {
        ListNode* help1 = new ListNode(-1), *help2 = new ListNode(-1);
        ListNode* list1 = help1 , *list2 = help2;
        ListNode* temp = head;

        while(temp) {
            if(x>temp->val) {
                help1 -> next = new ListNode(temp->val);
                help1 = help1->next;
            }
            else {
                help2->next = new ListNode(temp->val);
                help2 = help2->next;
            }
            temp = temp->next;
        }

        help1->next = list2->next;

        return list1->next;
    }
};
