class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int low=1, high=num/2;
        long long int mid=(high+low)/2;
        if(num == 1)
            return true;

        while(high>=low)
		{
			mid=(high+low)/2;
            if(mid*mid == num && num%mid == 0)
                return true;
			if(mid < num/mid)
				low=mid+1;
			else
				high=mid-1;
		}

        return false;
    }
};
