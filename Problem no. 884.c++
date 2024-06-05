class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v;

        s1 = s1 + " " + s2;
        int len = s1.length();
        string temp = "";

        for(int i=0;i<len;i++)
        {
            if(s1[i] != ' ')
                temp.push_back(s1[i]);

            else
            {
                v.push_back(temp);
                temp = "";
            }
        }

        v.push_back(temp);

        int size = v.size();

        unordered_map<string, int> mp;

        vector<string> result;

        for(int i=0;i<size;i++)
        {
            mp[v[i]]++;
        }

        for(auto it : mp)
        {
            if(it.second == 1)
                result.push_back(it.first);
        }

        return result;
    }
};
