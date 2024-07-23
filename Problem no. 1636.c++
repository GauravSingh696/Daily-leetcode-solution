//  23-07-2024

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int,int>> pr;

        for(auto it : mp)
        {
            pr.push_back({it.second , it.first});
        }

        sort(pr.begin(), pr.end());

        vector<int> result;
        int s = pr.size();
        set<int> st;

        for(int i=0;i<s;i++)
        {
            if((i<s-1) && (pr[i].first == pr[i+1].first))
            {
                st.insert(pr[i].second);
                st.insert(pr[i+1].second);
            }

            else
            {
                if(!st.empty())
                {
                    vector<int> temp;

                    for(auto it : st)
                    {
                        temp.push_back(it);
                    }

                    sort(temp.begin(), temp.end(), greater<>());

                    for(int j=0;j<temp.size();j++)
                    {
                        int t = pr[i].first;

                        while(t--)
                        {  
                            result.push_back(temp[j]);
                        }
                    }
                    
                    st.clear();
                    continue;
                }

                int t = pr[i].first;

                while(t--)
                {
                    result.push_back(pr[i].second);
                }
            }
        }

        return result;
    }
};
