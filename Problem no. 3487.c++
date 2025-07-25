class Solution {
public:
    int maxSum(vector<int>& nums) {
        int minus = INT_MIN;
        int idx = 0, n = nums.size();
        unordered_set<int> st;

        for(int &it : nums) {
            if(it < 0) {
                idx++;
                minus = max(minus, it);
            }

            else
                st.insert(it);
        }

        if(idx == n)
            return minus;
        
        int result = 0;

        for(int it : st) {
            result += it;
        }

        return result;
    }
};
