class Solution {
public:
    bool validPalindrome(string s) {
        string x = s;
        string y = s;
        reverse(s.begin(), s.end());

        if (x == s)
            return true;

        for (int i = 0; i < s.size(); i++) {
            if (x[i] != s[i]) {
                s.erase(s.begin() + i);
                break;
            }
        }

        x = s;
        reverse(s.begin(), s.end());

        if (x == s)
            return true;

        else {
            s = y;
            reverse(s.begin(), s.end());
            for (int i = 0; i < s.size(); i++)
            {
                if (y[i] != s[i]) {
                    y.erase(y.begin() + i);
                    break;
                }

            }
        }
        s=y;
        reverse(s.begin(), s.end());

        if (y == s)
            return true;

        return false;       
    }
};
