//  03-03-2024

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
    int length_travel(ListNode* head)
    {
        int l=0;
        while(head)
        {
            l++;
            head=head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=length_travel(head);
        if(length==n)
        {
            ListNode* temp=head->next;
            delete(head);
            return temp;
        }

        ListNode* temp=head;
        ListNode* prev=NULL;
        int travel=length-n;

        while(travel--)
        {
            prev=temp;
            temp=temp->next;
        }

        prev->next=temp->next;
        delete(temp);
        return head;
    }
};
