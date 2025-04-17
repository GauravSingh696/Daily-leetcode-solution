class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();

        for(int i=0;i<n;i++) {
            if(isalpha(word[i])) {
                word[i] = ' ';
            }
        }

        stringstream ss(word);
        string temp;

        unordered_set<string> st;

        while(ss >> temp) {
            int i = 0;

            while(temp[i] == '0')
                i++;
            
            string str;
            
            for(;i<temp.size();i++) {
                str += temp[i];
            }

            st.insert(str);
        }

        return st.size();
    }
};
