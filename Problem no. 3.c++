class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int result = 0;

        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            { 
                if(st.find(s[j]) != st.end())
                {
                    int n = st.size();
                    result = max(result, n);
                    st.clear();
                    break;
                }
            
                st.insert(s[j]);
            }

            int n = st.size();

            result = max(result, n);
        }

        return result;
    }
};
