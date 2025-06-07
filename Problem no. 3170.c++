class Solution {
public:
    typedef pair<char, int> Pr;

    struct comp{
        bool operator()(Pr &p1, Pr &p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        int n = s.size();
        priority_queue<Pr, vector<Pr>, comp> pq;

        for(int i=0;i<n;i++) {
            if(s[i] != '*')
                pq.push({s[i], i});
            
            else {
                int idx = pq.top().second;
                pq.pop();

                s[idx] = '*';
            }
        }

        string result;

        for(int i=0;i<n;i++) {
            if(s[i] != '*') 
                result.push_back(s[i]);
        }

        return result;
    }
};
