// 05-07-2024

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;
        
        while(head)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        vector<int> v;

        for(int i=1;i<vec.size()-1;i++)
        {
            if((vec[i-1] > vec[i]) && (vec[i+1] > vec[i]))
            {
                v.push_back(i+1);
            }
            if((vec[i-1] < vec[i]) && (vec[i+1] < vec[i]))
            {
                v.push_back(i+1);
            }
        }

        if(v.size() < 2)
            return {-1, -1};

        int min_=INT_MAX;
        int x = v.size();
        int max_ = v[x-1] - v[0];

        for(int i=1 ; i<x ; i++)
        {
            min_ = min(min_, v[i] - v[i - 1]);
        }

        return {min_ , max_};

    }
};
