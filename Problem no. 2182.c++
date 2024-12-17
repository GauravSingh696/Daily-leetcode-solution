class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        for(auto it : s) {
            freq[it-'a']++;
        }

        int i = 25;
        string result;

        while(i>=0) {
            if(freq[i]==0) {
                i--;
                continue;
            }
            
            char ch = 'a' + i;
            int repeat = min(freq[i] , repeatLimit);

            result.append(repeat , ch);
            freq[i] -= repeat;
            
            if(freq[i] > 0) {
                int j = i-1;
                while(j>=0 && freq[j]==0) {
                    j--;
                }

                if(j<0) {
                    break;
                }

                result.push_back('a' + j);
                freq[j]--;
            }
        }

        return result;
    }
};
