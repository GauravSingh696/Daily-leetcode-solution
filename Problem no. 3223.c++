class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int result = 0;

        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        for (auto it : freq) {
            if (it == 0) continue;
            if (it % 2 == 0) {
                result += 2;
            } else {
                result += 1;
            }
        }
        return result;
    }
};
