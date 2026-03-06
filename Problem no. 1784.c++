class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                if(flag) return false;

                while(i<s.size() && s[i] == '1') i++;
                
                flag = true;
            }
        }

        return true;
    }
};
