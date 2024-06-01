class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> st;
        string x="";
        for(int i=0 ; i<text.size() ; i++)
        {
            if(text[i]==' '){
                st.push_back(x);
                x="";
            }

            else{
                x+=text[i];
            }
        }
        st.push_back(x);
        vector<string> result;
        int n=st.size();
        for(int i=0 ; i<n-2 ; i++)
        {
            if(st[i]==first && st[i+1]==second)
                result.push_back(st[i+2]);
        }
        return result;
    }
};
