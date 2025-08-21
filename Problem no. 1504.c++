class Solution {
public:
    int OneDarrayCount(vector<int>& arr) {
        int count = 0, result = 0;

        for(int &it : arr) {
            if(it == 1)
                count++;
            
            else
                count = 0;

            result += count;
        }

        return result;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int result = 0;

        for(int rowStart=0;rowStart<rows;rowStart++) {
            vector<int> arr(cols, 1);

            for(int rowEnd=rowStart;rowEnd<rows;rowEnd++) {
                for(int col=0;col<cols;col++) {
                    arr[col] = arr[col] & mat[rowEnd][col];
                }

                result += OneDarrayCount(arr);
            }
        }

        return result;
    }
};
