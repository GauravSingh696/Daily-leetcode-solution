// 06-06-2024

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        map<int, int> mp;

        for(int i=0;i<len;i++)
        {
            mp[hand[i]]++;
        }

        vector<vector<int>> result;

        while(true)
        {
            int count = 0;
            vector<int> temp;

            for(auto &it : mp)
            {
                if(it.second != 0)
                {
                    count++;
                    temp.push_back(it.first);
                    it.second--;
                }

                if(count == groupSize)
                    break;
            }

            if(count == 0)
                break;
            
            result.push_back(temp);
        }

        int m = result.size();

        for(int i=0;i<m;i++)
        {
            if(result[i].size() != groupSize)
                return false;
        }

        for(int i=0;i<m;i++)
        {
            int n = result[i].size();

            for(int j=1;j<n;j++)
            {
                if((result[i][j]-result[i][j-1]) != 1)
                    return false;
            }
        }

        return true;
    }
};
