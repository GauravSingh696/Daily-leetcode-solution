class Solution {
public:
    string sortSentence(string s) {
        multimap<int, string> mp;
        string temp = "";

        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                int val = s[i] - '0';
                mp.insert(pair<int, string>(val, temp));
                temp = "";
            }

            else if(isalpha(s[i]))
                temp += s[i];
        }

        string result = "";

        for(auto it : mp)
        {
            result += it.second + " ";
        }

        result.pop_back();

        return result;

    }
};
