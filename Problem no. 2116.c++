class Solution {
public:
    bool canBeValid(string str, string lockStatus) {
        if (str.size() % 2 != 0) 
            return false;

        int openCount = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (lockStatus[i] == '0' || str[i] == '(') 
                openCount++;
            else 
                openCount--;
            if (openCount < 0) 
                return false;
        }

        openCount = 0;
        for (int i = str.size() - 1; i >= 0; --i) {
            if (lockStatus[i] == '0' || str[i] == ')') 
                openCount++;
            else 
                openCount--;
            if (openCount < 0) 
                return false;
        }
        return true;
    }
};
