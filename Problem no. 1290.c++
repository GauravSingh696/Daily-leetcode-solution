class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> x;
        while(head)
        {
            x.push_back(head->val);
            head=head->next;
        }
        
        int ans=0;
        int idx=0;
        for(int i=x.size()-1 ; i>=0 ; i--)
        {   
            ans+=(x[i]*pow(2,idx++));
        }
        return ans;
    }
};
