class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), :: tolower);
        int n=s.size();

        string arr="";
        for(int i=0;i<n;i++)
        {
            if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z'))
            {
                arr += s[i];
            }
        }

        string temp="";
        temp=arr;
        
        reverse(temp.begin(), temp.end());
        
        if(temp == arr)
            return true;
        
        else
            return false;
    }
};
