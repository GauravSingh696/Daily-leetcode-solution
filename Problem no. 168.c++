class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber>0)
        {
            columnNumber--;
            int rem = columnNumber%26;
            char ch = rem+'A';
            result.push_back(ch);
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
