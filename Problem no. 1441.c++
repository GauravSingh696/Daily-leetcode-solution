class Solution {
public:
    vector<string> buildArray(vector<int>& tar, int n) {
        vector<string> result;
        int size = tar.size();
        int i=0 , j=1;

        while(i<size && j<=n) {
            result.push_back("Push");

            if(j != tar[i]) {
                result.push_back("Pop");
            }

            else {
                i++;
            }

            j++;
        }

        return result;
    }
};
