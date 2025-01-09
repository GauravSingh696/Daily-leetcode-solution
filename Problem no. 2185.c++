class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;

        for(auto &it : words) {
            if(it.find(pref) == 0)
                result++;
        }

        return result;
    }
};
