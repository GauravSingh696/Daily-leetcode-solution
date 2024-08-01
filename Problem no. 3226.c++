class Solution {
public:
    int minChanges(int n, int k) {
        string s1 = bitset<32>(n).to_string();
        string s2 = bitset<32>(k).to_string();

        int result = 0;

        for(int i=0;i<32;i++)
        {
            if(s1[i] == '1')
            {
                if(s2[i] == '0')
                {
                    s1[i] = '0';
                    result++;
                }
            }
        }

        if(s1 == s2)
            return result;
        
        return -1;
    }
};
