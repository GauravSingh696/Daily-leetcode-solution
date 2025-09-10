class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sad_user;

        for(auto fr : friendships) {
            int u = fr[0]-1, v = fr[1]-1;

            unordered_set<int> st(languages[u].begin(), languages[u].end());
            bool canTalk = false;

            for(auto it : languages[v]) {
                if(st.count(it)) {
                    canTalk = true;
                    break;
                }
            }
            
            if(!canTalk) {
                sad_user.insert(u);
                sad_user.insert(v);
            }
        }

        vector<int> lang(n+1, 0);
        int most_known_lang = 0;

        for(auto it : sad_user) {
            for(auto l : languages[it]) {
                lang[l]++;
                most_known_lang = max(most_known_lang, lang[l]);
            }
        }

        return sad_user.size() - most_known_lang;
    }
};
