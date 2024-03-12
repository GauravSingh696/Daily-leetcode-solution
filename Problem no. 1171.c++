//  12-03-2024

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        unordered_map<int, ListNode*> mp;
        ListNode* newnode = new ListNode(0);
        newnode->next = head;
        mp[0]=newnode;

        while(head)
        {
            prefixSum += head->val;
            if(mp.find(prefixSum)!=mp.end())
            {
                ListNode* p=mp[prefixSum];
                ListNode* start=p;

                int pSum=prefixSum;
                while(start!=head)
                {
                    start = start->next;
                    pSum += start->val;

                    if(start!=head)
                    {
                        mp.erase(pSum);
                    }
                }

                p->next=start->next;
            }
            else
            {
                mp[prefixSum]=head;
            }

            head=head->next;
        }

        return newnode->next;
    }
};
