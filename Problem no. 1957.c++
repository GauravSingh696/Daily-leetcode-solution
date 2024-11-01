// 01-11-2024

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        
        if (s.size() <= 2)
            return s;
        
        result.push_back(s[0]);
        result.push_back(s[1]);
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue;
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
