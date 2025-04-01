class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int flag = -1;

        for(int i=0;i<groups.size();i++) {
            if(groups[i] != flag) {
                flag = groups[i];
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
