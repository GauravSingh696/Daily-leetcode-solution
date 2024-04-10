class Solution {
public:
    int countSegments(string s) {
        int result=0;
        string temp="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' && temp!="")
            {
                result++;
                temp="";
            }

            else if(s[i]==' ')
            {
                continue;
            }

            else
            {
                temp += s[i];
            }
        }

        if(temp!="")
        {
            result++;
        }

        return result;
    }
};
