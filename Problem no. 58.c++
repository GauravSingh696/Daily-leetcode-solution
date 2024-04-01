// 01-04-2024

// approach 1
class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ')+1);  // removes the tailing spaces.

        int lastSpace=s.find_last_of(' ');

        return lastSpace==string::npos ? s.length() : s.length() - lastSpace-1;
    }
};

// approach 2

int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int i,count=0,check=0;
    for(i=len-1;i>=0;i--)
    {
        if(s[i]==' ')
        {
            check++;
        }
        else
            break;
    }
    for(int j=len-check-1;j>=0;j--)
    {
        if(s[j]!=' ')
        {
            count++;
        }
        else
            break;
    }
    return count;
}
