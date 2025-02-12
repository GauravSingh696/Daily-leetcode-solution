class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int prev_with_del = 0 , prev_not_del = arr[0];
        int result = arr[0];

        for(int i=1;i<arr.size();i++) {
            prev_with_del = max(prev_not_del , arr[i] + prev_with_del);
            prev_not_del  = max(prev_not_del + arr[i] , arr[i]);

            result = max(result , prev_with_del);
            result = max(result , prev_not_del);
        }

        return result;
    }
};
