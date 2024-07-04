class Solution {
public:
    string generateTheString(int n) {
        string re="";

        if(n%2==0){
            for(int i=0;i<n-1;i++)
                re=re+"a";
            re = re+"b";
        }
        
        else
            for(int i=0;i<n;i++)
                re=re+"a";
        return re;
    }
};
