class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> it;

        for(int i=0;i<n-1;i++)
        {
            int it = *max_element(arr.begin()+i+1 , arr.end());

            arr[i] = it;
        }

        arr[n-1] = -1;

        return arr;
    }
};
