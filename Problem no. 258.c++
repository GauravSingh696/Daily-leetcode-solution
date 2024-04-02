// first approach.

class Solution {
public:
    int addDigits(int num) {
        int result;

        if(num < 10)
            return num;
        
        else
        {
            level:
                result=0;
                while(num)
                {
                    int rem = num%10;
                    result += rem;
                    num = num/10;
                }
                if(result > 9)
                {
                    num = result;
                    goto level;
                }
        }

        return result;
    }
};


// second approach.

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        
        return 1 + (num-1)%9;
    }
};
