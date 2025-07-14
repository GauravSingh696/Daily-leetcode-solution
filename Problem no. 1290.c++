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
    int getDecimalValue(ListNode* head) {
        string str;

        while(head) {
            str += (char)head->val;
            head = head->next;
        }

        int k = 0, result = 0;

        for(int i=str.size()-1;i>=0;i--) {
            result += str[i] * pow(2, k++);
        }

        return result;
    }
};
