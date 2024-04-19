class Solution {
public:
    bool check(string s, char ch)
    {
        for(auto &it : s)
        {
            if(it == ch)
                return true;
        }
        return false;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> v = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int n=words.size();
        vector<string> result;

        for(int i=0;i<n;i++)
        {
            for(int k=0;k<3;k++)
            {
                bool found = true;
                for(int j=0;j<words[i].size();j++)
                {
                    if(!check(v[k], tolower(words[i][j])))
                        found = false;
                }

                if(found)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};
