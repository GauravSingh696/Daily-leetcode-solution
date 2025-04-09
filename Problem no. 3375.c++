class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        int result = 0;
        bool flag = true;

        for(auto &it : st) {
            if(flag && it < k) {
                return -1;
                flag = false;
            }

            if(it > k)
                result++;
        }

        return result ;
    }
};
