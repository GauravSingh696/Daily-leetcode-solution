class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;

        for(int &it : arr) {
            mp[it]++;
        }

        int largest = -1;

        for(auto &it : mp) {
            if(it.first == it.second)
                largest = it.first;
        }

        return largest;
    }
};
