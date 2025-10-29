class Solution {
public:
    int smallestNumber(int n) {
        int next_power = 1;

        while (next_power <= n) {
            next_power <<= 1;
        }

        return next_power - 1;
    }
};
