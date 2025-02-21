class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        int n = pushed.size();
        stack<int> st;

        while(i<n && j<n) {
            st.push(pushed[i++]);

            while(!st.empty() && st.top() == popped[j]) {
                j++;
                st.pop();
            }
        }

        return st.empty();
    }
};
