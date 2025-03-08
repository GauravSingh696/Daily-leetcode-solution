class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0 , j=0;
        int n = blocks.size();
        int result = INT_MAX;
        int temp = 0;

        while(j<n) {
            if(blocks[j] == 'W') {
                blocks[j] = '*';
                temp++;
            }

            if(j-i+1 == k) {
                result = min(result , temp);

                if(blocks[i] == '*') {
                    temp--;
                }

                i++;
            }

            j++;
        }

        return result;
    }
};
