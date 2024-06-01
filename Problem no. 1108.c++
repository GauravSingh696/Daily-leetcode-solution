class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.length();

        string st = "";

        for(int i=0;i<len;i++)
        {
            if(address[i] != '.')
                st.push_back(address[i]);
            else
            {
                st.push_back('[');
                st.push_back('.');
                st.push_back(']');
            }
        }

        return st;
    }
};
