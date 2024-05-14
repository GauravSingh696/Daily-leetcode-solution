class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        while(left <= right)
        {
            int num = left;
            bool flag = true;

            while(num)
            {
                int rem = num%10;
                if( (rem==0) || (left % rem) != 0)
                {
                    flag = false;
                    break;
                }

                num /=10;
            }

            if(flag == true)
                result.push_back(left);
            
            left++;
        }

        return result;
    }
};
