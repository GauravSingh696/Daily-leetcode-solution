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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        if(head==NULL || head->next == NULL || k==0){
            return head;
        }

        int n = 0;
        ListNode* node = head;

        while(node) {
            n++;
            node = node->next;
        }

        ListNode* new_node = head;
        if(k > n)
            k = k%n;
        if(k==0)
            return head;
        n = n-k;

        if(n==0)
            return head;

        ListNode* temp = NULL;

        while(new_node) {
            n--;

            if(n<=0) {
                temp = new_node->next;
                new_node->next = NULL;
                break;
            }

            new_node = new_node->next;
        }

        ListNode* result = temp ;
        ListNode* prev = NULL;

        while(temp) {
            prev = temp;
            temp = temp->next;
        }

        if(prev)
            prev->next = head;

        return result;
    }
};
