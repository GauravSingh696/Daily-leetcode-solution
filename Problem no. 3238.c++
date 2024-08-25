class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<int> vec;

        for(int i=0;i<n;i++)
        {
            unordered_map<int, int> mp;

            for(int j=0;j<pick.size();j++)
            {
                if(pick[j][0] == i)
                {
                    mp[pick[j][1]]++;
                }
            }

            int a = INT_MIN;

            for(auto it : mp)
                a = max(a , it.second);
            
            if(mp.size() > 0)
                vec.push_back(a);
            
            else
                vec.push_back(0);
        }

        int result = 0;

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i] > i)
                result++;
        }

        return result;
    }
};
