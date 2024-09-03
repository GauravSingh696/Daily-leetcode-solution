// 03-09-2024

class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        --k;

        for(auto it : s)
        {
            int val = it - '`';

            if(val > 9)
            {
                while(val)
                {
                    sum += val % 10;
                    val /= 10;
                }
            }
            else
            {
                sum += it - '`';
            }
        }

        while(k--)
        {
            if(k<0)
                break;
            int num = sum;
            sum = 0;

            while(num)
            {
                sum += num%10;
                num /= 10;
            }
        }

        return sum;
    }
};
