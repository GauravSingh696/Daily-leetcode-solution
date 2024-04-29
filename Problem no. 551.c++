class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int p=0, a=0, l=0, i=0;
        
        while(i<n)
        {
            if(s[i]=='P')
            {
                p++;
                i++;
            }
            
            else if(s[i]=='A')
            {
                a++;
                i++;
            }
            
            else
            {
                while(s[i]=='L' && i<n)
                {
                    l++;
                    i++;
                }

                if(l>=3)
                    return false;
                
                else
                {
                    l=0;
                }
            }
        }

        if(a>=2)
            return false;
        
        return true;
    }
};
