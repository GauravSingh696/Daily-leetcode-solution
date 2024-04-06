// 06-04-2024

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        string temp="";

        for(char ch:s)
        {
            if(ch=='(')
                open++;
            
            else if(ch==')')
            {
                if(open==0)
                    continue;

                open--;
            }

            temp.push_back(ch);
        }

        int n=temp.size();
        string result="";
        
        for(int i=n-1;i>=0;i--)
        {
            if(temp[i] == '(' && open-- > 0)
                continue;
            
            result.push_back(temp[i]);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
