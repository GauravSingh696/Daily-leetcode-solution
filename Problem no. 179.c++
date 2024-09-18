// 18-09-2024

bool compare(int &a, int &b) {
    string sa = to_string(a);
    string sb = to_string(b);

    return (sa + sb ) > (sb + sa);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        if(nums[0] == 0)
            return "0";

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};
