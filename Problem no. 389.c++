class Solution {
public:
    char findTheDifference(string s, string t) {
        s.append(t);
        char result=s[0];

        for(int i=1;i<s.size();i++)
        {
            result ^= s[i];
        }

        return result;
    }
};
