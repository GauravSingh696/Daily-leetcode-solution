//  11-04-2024

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();

        string result="";

        for(int i=0;i<n;i++)
        {
            while(result.length()>0 && result.back()>num[i] && k>0)
            {
                result.pop_back();
                k--;
            }

            if(result.length()>0 || num[i]!='0')
                result.push_back(num[i]);
        }

        while(result.length()>0 && k>0)
        {
            result.pop_back();
            k--;
        }

        if(result=="")
            return "0";

        return result;
    }
};
