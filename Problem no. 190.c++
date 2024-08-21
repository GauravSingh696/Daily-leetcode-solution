class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        string s = bitset<32>(n).to_string();
        for (int i = 0; i < 32; i++) {
            if (s[i] == '1')
                ans += pow(2, i);
        }
        return ans;
    }
};
