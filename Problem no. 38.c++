class Solution {
public:
    string countAndSay(int n) {
        string st="1";

        for(int i=2;i<=n;i++) {
            string new_st;

            for(int j=0;j<st.size();j++) {
                char ch = st[j];
                int count = 1;
                j++;

                while(j<st.size() && ch == st[j]) {
                    j++;
                    count++;
                }
              
                j--;
                new_st += to_string(count) + ch;
            }
            
            st = new_st;
        }

        return st;
    }
};
