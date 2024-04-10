class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        int i=m-1, j=n-1, carry=0;
        string result = "";

        while(i>=0 || j>=0 || carry)
        {
            int digit1 = (i>=0) ? num1[i]-'0' : 0;
            int digit2 = (j>=0) ? num2[j]-'0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum/10;
            result = to_string(sum%10)+result;
            i--;
            j--;
        }

        return result;
    }
};
