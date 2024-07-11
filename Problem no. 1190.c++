class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i]=='(')
            {
                st.push(i+1);
            }
            else if(s[i]==')')
            {
                reverse(s.begin()+st.top(),s.begin()+i);
                st.pop();
            }
        }
        string a="";
        for(auto it:s)
        {
            if(it>='a' && it<='z')
            {
                a+=it;
            }
        }
        return a;
    }
};
