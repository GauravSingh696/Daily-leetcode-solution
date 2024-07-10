class Solution {
public:
    vector<string> stringMatching(vector<string>& w) {
        vector<string> ans;

        for(auto i : w)
        {
            for(auto j : w)
            {
                if(i != j)
                {
                    int temp = j.find(i);

                    if(temp >= 0)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
