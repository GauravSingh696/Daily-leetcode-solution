class Solution {
public:
    bool hasAlternatingBits(int n) {
        string st = bitset<32> (n).to_string();
        int i;

        for(i=0;i<32;i++) {
            if(st[i]!='0')
                break;
        }

        for(int j=i ; j<st.size() ; j++) {   
            if(st[j]==st[j+1])
                return false;
        }

        return true;
    }
};
