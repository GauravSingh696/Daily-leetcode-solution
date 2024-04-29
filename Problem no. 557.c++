class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int count = 0;
        string result = "";

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ' || i==n-1)
            {
                int temp = i-1;
                
                if(i==n-1)
                {
                    temp = i;
                    count++;
                }

                while(count--)
                {
                    result += s[temp--];
                }

                if(i!=n-1)
                    result += " ";
                count = 0;
            }

            else
            {
                count++;
            }
        }

        return result;
    }
};
