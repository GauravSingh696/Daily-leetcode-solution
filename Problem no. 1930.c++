// approach 1 ............

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;

        unordered_set<char> st(s.begin() , s.end());

        for(auto it : st) {
            int left_idx  = -1;
            int right_idx = -1;

            for(int i=0 ; i<s.size() ; i++) {
                if(s[i] == it) {
                    if(left_idx == -1)
                        left_idx = i;
                    
                    right_idx = i;
                }
            }

            unordered_set<char> temp;

            for(int i=left_idx+1 ; i<right_idx ; i++) {
                temp.insert(s[i]);
            }

            result += temp.size();
        }

        return result;
    }
};



// approach 2 ............

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;

        vector<pair<int, int>> idx(26, {-1, -1});

        for(int i=0 ; i<s.size() ; i++) {
            int index = s[i] - 'a';

            if(idx[index].first == -1) {
                idx[index].first = i;
            }

            idx[index].second = i;
        }

        for(auto it : idx) {
            int left_idx  = it.first;
            int right_idx = it.second;

            if(left_idx == -1)
                continue;

            unordered_set<char> temp;

            for(int i=left_idx+1 ; i<right_idx ; i++) {
                temp.insert(s[i]);
            }

            result += temp.size();
        }

        return result;
    }
};
