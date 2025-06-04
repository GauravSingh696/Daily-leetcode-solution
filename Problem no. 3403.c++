class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        
        int n = word.size();
        int longestPossible = n - (numFriends-1);
        string result;

        for(int i=0;i<n;i++) {
            int take_length = min(longestPossible, n-i);

            result = max(result, word.substr(i, take_length));
        }

        return result;
    }
};
