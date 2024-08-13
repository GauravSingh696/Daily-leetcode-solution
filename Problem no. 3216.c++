class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();

        for(int i=0;i<n-1;i++)
        {
            if(((s[i]-'0')%2 == 0) && ((s[i+1]-'0')%2 == 0) && s[i] > s[i+1])
            {
                swap(s[i], s[i+1]);
                break;
            }
            else if(((s[i]-'0')%2 != 0) && ((s[i+1]-'0')%2 != 0) && s[i] > s[i+1])
            {
                swap(s[i], s[i+1]);
                break;
            }
        }

        return s;
    }
};
