// 01-06-2024

class Solution {
public:
    int scoreOfString(string s) {
        int len = s.length();
        int sum = 0;

        for(int i=1;i<len;i++)
        {
            sum += abs(s[i]-s[i-1]);
        }

        return sum;
    }
};
