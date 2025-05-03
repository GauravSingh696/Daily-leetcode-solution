class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        int n = arr.size();

        for(int i=0;i<n;i++) {
            int sum = 0;

            for(int j=i;j<n;j++) {
                sum += arr[j];

                if((j-i+1)%2 != 0) {
                    result += sum;
                }
            }
        }

        return result;
    }
};
