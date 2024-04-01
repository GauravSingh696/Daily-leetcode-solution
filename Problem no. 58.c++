// 01-04-2024

class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ')+1);  // removes the tailing spaces.

        int lastSpace=s.find_last_of(' ');

        return lastSpace==string::npos ? s.length() : s.length() - lastSpace-1;
    }
};
