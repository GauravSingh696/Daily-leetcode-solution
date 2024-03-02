class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch : s)
        {
            if(st.empty() || ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }

            else if(ch==')')
            {
                if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }

            else if(ch=='}')
            {
                if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }

            else if(ch==']')
            {
                if(st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
