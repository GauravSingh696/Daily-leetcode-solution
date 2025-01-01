class Solution {
public:
    int maxScore(string s) {
        int count = 0 , n = s.size();
        vector<int> pre_count(n);
        vector<int> post_count(n);

        for(int i=0;i<n;i++) {
            if(s[i] == '0')
                count++;
            pre_count[i] = count;
        }

        count = 0;

        for(int i=n-1;i>=0;i--) {
            if(s[i] == '1')
                count++;
            
            post_count[i] = count;
        }

        int result = 0;

        for(int i=0;i<n-1;i++) {
            result = max(result , pre_count[i] + post_count[i+1]);
        }

        return result;

    }
};
