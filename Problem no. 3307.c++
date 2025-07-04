class Solution {
public:
    char solve(long long k, vector<int> &operations) {
        if(k == 1)
            return 'a';
        
        long long length = 1, new_k = -1, operation_type = -1;

        for(int i=0;i<operations.size();i++) {
            length *= 2;

            if(length >= k) {
                operation_type = operations[i];
                new_k = k - length/2;
                break;
            }
        }

        char ch = solve(new_k, operations);

        if(operation_type)
            return ch == 'z' ? 'a' : ++ch;
        else
            return ch;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        return solve(k, operations);
    }
};
