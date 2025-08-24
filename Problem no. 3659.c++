class Solution {
  public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n%k != 0)
            return false;

        int groups = n / k;
        unordered_map<int, int> freq;

        for(int it : nums) {
            freq[it]++;
        }

        for(auto it : freq) {
            if(it.second > groups)
                return false;
        }

        return true;
    }
};
