// 10-06-2024

class Solution {
public:
    int heightChecker(vector<int>& h) {

        vector<int> v = h;
        sort(h.begin(), h.end());
        int count = 0;

        for(int i=0;i<h.size();i++)
        {
            if(h[i] != v[i])
                count++;
        }

        return count;
    }
};
