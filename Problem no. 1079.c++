class Solution {
private:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, countLeft] : freq) {
            if (countLeft > 0) {
                // Choose character
                count++;
                freq[ch]--;

                // Recurse to form more sequences
                count += backtrack(freq);

                // Undo choice (backtrack)
                freq[ch]++;
            }
        }
        return count;
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char tile : tiles) {
            freq[tile]++;
        }
        return backtrack(freq);
    }
};
