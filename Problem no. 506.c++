class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score);
        vector<string> result;

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        unordered_map<int, int> mp;

        for(int i=0;i<temp.size();i++)
        {
            mp[temp[i]]=(i+1)*(-1);
        }

        for(int i=0;i<score.size();i++)
        {
            if(mp[score[i]] == -1)
                result.push_back("Gold Medal");
            
            else if (mp[score[i]] == -2)
                result.push_back("Silver Medal");
            
            else if (mp[score[i]] == -3)
                result.push_back("Bronze Medal");
            
            else
            {
                result.push_back(to_string(mp[score[i]]*-1));
            }
        }
        
        return result;
    }
};
