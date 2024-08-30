class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int m=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0 ; i<arr.size()-1 ; i++)
        {
            m=min(m,abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>> result;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i+1] - arr[i] == m) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        return result;
    }
};
