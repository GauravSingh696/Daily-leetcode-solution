// 09-09-2024

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        ListNode* temp = head;

        int n = 0;
        
        while(temp)
        {
            n++;     temp = temp->next;
        }

        int mod = n%k;
        int arr_size = n/k;

        temp = head;

        if(n==1 && k==1)
            return {head};

        if(k>=n)
        {
            while(temp)
            {
                ListNode* prev = temp->next;
                result.push_back(temp);
                temp->next = NULL;

                temp = prev;
                k--;
            }

            while(k--)
                result.push_back({});

            return result;
        }

        ListNode* curr;

        while(temp)
        {
            ListNode *prev = temp;
            int t = arr_size;

            while(--t && temp->next)
            {
                temp = temp->next;
            }

            if(mod > 0 && temp->next)
            {
                temp = temp->next;
                mod--;
            }

            curr = temp->next;
            temp->next = NULL;

            result.push_back(prev);

            temp = curr;
        }

        return result;
    }
};
