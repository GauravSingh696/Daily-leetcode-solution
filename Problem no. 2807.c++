// 10-09-2024

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
    int GCD(int a,int b){
        if(b==0)
            return a;
        
        return GCD(b , a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* ans=head;
        while(head->next){
            int x=GCD(head->val,head->next->val);
            ListNode* temp=new ListNode(x);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;
        }
        return ans;
    }
};
