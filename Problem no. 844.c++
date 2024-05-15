class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<char> v1;
        vector<char> v2;

        for(int i=0;i<m;i++)
        {
            if(s[i] == '#')
            {
                if(!v1.empty())
                    v1.pop_back();
            }
            else
            {
                v1.push_back(s[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(t[i] == '#')
            {
                if(!v2.empty())
                    v2.pop_back();
            }

            else
            {
                v2.push_back(t[i]);
            }
        }

        return v1==v2;
    }
};
