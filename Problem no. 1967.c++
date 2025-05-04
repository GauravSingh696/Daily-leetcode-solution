class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;

        for(auto &it : patterns) {
            if(word.find(it) < word.size()) {
                result++;
            }
        }

        return result;
    }
};
