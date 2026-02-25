class Solution {
  public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;

        for (auto it : arr) {
            string temp = bitset<20>(it).to_string();

            int c = count(temp.begin(), temp.end(), '1');

            v.push_back({c, it});
        }

        sort(v.begin(), v.end());

        vector<int> result;

        for (auto it : v) {
            result.push_back(it.second);
        }

        return result;
    }
};
