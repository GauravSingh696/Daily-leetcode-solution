class Solution {
public:
    int numberOfChild(int n, int k) {      
        int temp = -1;
        bool flag = true;
        
        while(k>=0)
        {
            if(flag == true)
            {
                temp++;
                
                if(temp == n-1)
                    flag = false;
            }
            
            else
            {
                if(temp == 1 )
                    flag = true;
                
                temp--;
            }
            
            k--;
        }
        
        return temp;
    }
};
