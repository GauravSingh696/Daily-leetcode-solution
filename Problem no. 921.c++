// 09-10-2024

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int result = 0;

        for(auto it : s) {
            if(it == '(')
                st.push(it);
            else
            {
                if(st.empty()) {
                    result++;
                    continue;
                }

                st.pop();
            }
        }

        return result + st.size();
    }
};
