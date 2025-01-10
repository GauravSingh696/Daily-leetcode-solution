class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_set<string> st;
        unordered_map<char , int> mp;

        for(auto &it : words2) {
            unordered_map<char , int> temp;

            for(auto &s : it) {
                temp[s]++;

                mp[s] = max(mp[s] , temp[s]);
            }
        }

        vector<string> result;

        for(auto it : words1) {
            unordered_map<char , int> temp;
            bool flag = true;

            for(auto i : it) {
                temp[i]++;
            }

            for(auto i : mp) {
                if(i.second > temp[i.first]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                result.push_back(it);
            }
        }

        return result;
    }
};
