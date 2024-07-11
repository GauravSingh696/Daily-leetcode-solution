class Solution {
public:
    string reformat(string s) {
        string result="";
        int n = s.length();

        int a=0, b=0;

        for(int i=0;i<n;i++)
        {
            if(s[i] >='a' && s[i] <= 'z')
                a++;
            
            if(s[i] >='0' && s[i] <= '9')
                b++;
        }

        queue<char> s1;
        queue<char> s2;

        for(int i=0;i<n;i++)
        {
            if(s[i] >='a' && s[i] <= 'z')
                s1.push(s[i]);
            
            else
                s2.push(s[i]);
        }

        if((a == b) || (a-1 == b) ||(a == b-1))
        {
            if(a<b)
            {
                queue<char> temp = s1;
                s1 = s2;
                s2 = temp;
            }

            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                    result += s1.front();
                    s1.pop();
                }
            
                else
                {
                    result += s2.front();
                    s2.pop();
                }
            }
        }
        return result;
    }
};
