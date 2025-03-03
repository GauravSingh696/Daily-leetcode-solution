class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int count_pivot = count(nums.begin(), nums.end(), pivot);

        for(auto it : nums) {
            if(it < pivot)
                less.push_back(it);
            else if(it > pivot)
                greater.push_back(it);
        }

        while(count_pivot--) {
            less.push_back(pivot);
        }

        for(auto it : greater) {
            less.push_back(it);
        }

        return less;
    }
};
