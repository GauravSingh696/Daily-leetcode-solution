class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result="";
        int k = 0;

        for(int i=0;i<s.size();i++) {
            if(k < spaces.size() && spaces[k] == i) {
                result += ' ';
                k++;
            }
            result += s[i];
        }

        return result;
    }
};
