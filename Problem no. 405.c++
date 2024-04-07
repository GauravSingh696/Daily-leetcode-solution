class Solution {
public:
    string toHex(int n) {
        if (n == 0) return "0"; // Handle special case of 0

        string ans = "";
        unsigned int num = n; // Use unsigned int for bit manipulation

        while (num != 0) {
            int rem = num % 16;
            char ch;
            if (rem < 10) {
                ch = rem + '0'; // Convert digit to character
            } else {
                ch = rem - 10 + 'a'; // Convert digit to lowercase hexadecimal character
            }
            ans = ch + ans;
            num = num / 16;
        }

        return ans;
    }
};
