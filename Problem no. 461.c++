class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=0;

        string st1 = bitset<32>(x).to_string();
        string st2 = bitset<32>(y).to_string();

        for(int i=0;i<32;i++)
        {
            if(st1[i] != st2[i])
                result++;
        }

        return result;
    }
};
