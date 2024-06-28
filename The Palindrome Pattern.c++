// 29-06-2024

class Solution {
  public:
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        
        int n = arr.size();
        
        for(int row=0;row<n;row++)
        {
            int idx = n;
            
            vector<int> temp(arr[row]);
            
            for(int col=0;col<n/2;col++)
            {
                swap(temp[col] , temp[--idx]);
            }
            
            if(temp == arr[row])
            {
                string st = "";
                st += to_string(row) + " R";
                
                return st;
            }
        }
        
        vector<vector<int>> vec;
        
        for(int row=0;row<n;row++)
        {
            vector<int> temp;
            
            for(int col=0;col<n;col++)
            {
                temp.push_back(arr[col][row]);
            }
            
            vec.push_back(temp);
        }
        
        for(int row=0;row<n;row++)
        {
            int idx = n;
            
            vector<int> temp(vec[row]);
            
            for(int col=0;col<n/2;col++)
            {
                swap(temp[col] , temp[--idx]);
            }
            
            if(temp == vec[row])
            {
                string st = "";
                st += to_string(row) + " C";
                
                return st;
            }
        }
        
        return "-1";
        
    }
};
