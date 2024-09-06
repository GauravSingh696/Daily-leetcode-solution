// 06-09-2024

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;

        for(auto it : nums)
        {
            st.insert(it);
        }

        ListNode* temp = head;

        while(st.find(temp->val) != st.end())
        {
            temp = temp->next;
        }

        head = temp;

        if(!head || !head->next)
            return head;
        
        ListNode* curr;

        while(temp)
        {
            if(st.find(temp->val) != st.end())
            {
                curr->next = temp->next;
                temp = temp->next;
            }
            
            else
            {
                curr = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
