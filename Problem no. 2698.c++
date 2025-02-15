class Solution {
public:
    bool check(int i, string str, int val, int curr_sum) {
        if(i==str.size())
            return curr_sum == val;
        
        if(curr_sum > val)
            return false;
        
        bool possible = false;
        
        for(int j=i;j<=str.length();j++) {
            string curr_str = str.substr(i, j-i+1);
            int add_curr = stoi(curr_str);

            possible = possible || check(j+1, str, val , curr_sum + add_curr);

            if(possible)
                return true;
        }

        return possible;
    }

    int punishmentNumber(int n) {
        int result = 0;

        for(int i=1;i<=n;i++) {
            int val = i*i;
            string str = to_string(val);

            if(check(0, str, i, 0)) {
                result += val;
            }
        }

        return result;
    }
};
