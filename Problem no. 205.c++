class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        if(s.size()!=t.size())
            return false;

        for(int i=0;i<s.length();i++)
        {
            if(mp1.find(s[i]) == mp1.end())
                mp1[s[i]]=i;
        }

        for(int i=0;i<t.length();i++)
        {
            if(mp2.find(t[i]) == mp2.end())
                mp2[t[i]]=i;
        }

        for(int i=0;i<s.length();i++)
        {
            if(mp1[s[i]] != mp2[t[i]])
                return false;
        }

        return true;
    }
};
