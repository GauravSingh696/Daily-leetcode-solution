// 04-06-2024

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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* result = new ListNode();
        ListNode* curr = result;
        int sum = 0;

        while(head)
        {
            if(head->val != 0)
            {
                sum += head->val;
                head = head->next;
            }

            else
            {
                if(sum > 0)
                {
                    curr->next = new ListNode(sum);
                    curr = curr->next;
                }
                head = head->next;
                sum = 0;
            }
        }

        return result->next;

    }
};
