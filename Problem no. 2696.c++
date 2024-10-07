// 07-10-2024

class Solution {
public:
    int minLength(string s) {
        stack<int> st;

        for(auto it : s) {
            if(st.empty()) {
                st.push(it);
                continue;
            }

            if(it=='B' && st.top()=='A') {
                st.pop();
                continue;
            }

            else if(it=='D' && st.top()=='C') {
                st.pop();
            }

            else
                st.push(it);
        }

        return st.size();
    }
};
