class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int result = 0;

        for(auto it : hours)
        {
            if(it >= target)
                result++;
        }

        return result;
    }
};
