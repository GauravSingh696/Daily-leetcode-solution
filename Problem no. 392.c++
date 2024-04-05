class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int i=0,j=0;
        
        while(i<n)
        {
            if(t[i]==s[j])
                j++;
            
            i++;
        }

        if(j==m)
            return true;
        
        return false;
    }
};
