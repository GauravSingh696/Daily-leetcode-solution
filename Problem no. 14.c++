class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int a=strs[0].size();
        int b=strs[n-1].size();
        string newstrs="";
        int k=0;
        for(int i=0;i<a;i++)
        {
            if(strs[0][i]!=strs[n-1][i])
            {
                if(k==0)
                    return "";
                else
                    return newstrs;
            }
            else
            {
                newstrs.push_back(strs[0][i]);
                k=9;
            }
        }
        return newstrs;
    }
};
