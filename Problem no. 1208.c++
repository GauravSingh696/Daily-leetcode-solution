// 28-05-2024

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();

        int i=0, j=0;
        int curr_cost = 0;
        int max_len = 0;

        while(j<n)
        {
            curr_cost += abs(s[j] - t[j]);

            while(curr_cost > maxCost)
            {
                curr_cost -= abs(s[i] - t[i]);
                i++;
            }

            max_len = max(max_len , j-i+1);
            j++;
        }

        return max_len;
    }
};
