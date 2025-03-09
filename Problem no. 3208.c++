class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        for(int i=0;i<k-1;i++) {
            colors.push_back(colors[i]);
        }

        int i=0, j=1;
        int result = 0;
        n = colors.size();

        while(j<n) {
            if(colors[j] == colors[j-1])
                i = j;
            
            if(j-i+1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};
