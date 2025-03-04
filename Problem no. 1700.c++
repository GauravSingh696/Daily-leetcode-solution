class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que(students.begin(), students.end());
        stack<int> st;

        int n = sandwiches.size();

        for(int i=n-1;i>=0;i--) {
            st.push(sandwiches[i]);
        }

        int count = 0;

        while(!st.empty()) {
            if(que.front() == st.top()) {
                que.pop();
                st.pop();
                count = 0;
            }
            else {
                count++;
                int val = que.front();
                que.push(val);
                que.pop();
            }

            if(count == que.size()) {
                break;
            }
        }

        return st.empty() ? 0 : count ;
    }
};
