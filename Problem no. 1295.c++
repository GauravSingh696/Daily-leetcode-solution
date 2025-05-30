class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for(auto &it : nums) {
            string temp = to_string(it);

            if(temp.size()%2 == 0)
                result++;
        }

        return result;
    }
};
