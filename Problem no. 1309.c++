class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        int n=s.size()-1;
        for(int i=n ; i>=0 ; i--)
        {
            if(s[i]=='#')
            {
                int z=(s[i-2]-'0')*10+(s[i-1]-'0');
                char c='a'+z-1;
                ans=c+ans;
                i-=2;  
            }   
            else
            {
                char c='a'+(s[i]-'0')-1;
                ans=c+ans;
            }         
        }
        return ans;
    }
};
