class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";

        string result = "";
        int temp = num;

        num = abs(num);

        while(num)
        {
            int rem = num%7;
            result = char(rem + '0') + result;
            num /= 7;
        }

        if(temp<0)
            result = char('-') + result;

        return result;
    }
};
