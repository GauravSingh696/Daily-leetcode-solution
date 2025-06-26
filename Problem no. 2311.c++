class Solution {
public:
    int longestSubsequence(string s, int k) {
        int power_value = 1; // 2^0
        int length = 0;

        for(int i=s.size()-1;i>=0;i--) {
            if(s[i] == '0')
                length++;
            
            else if(power_value <= k) {
                k -= power_value;
                length++;
            }

            if(power_value <= k)
                power_value <<= 1;
        }

        return length;
    }
};
