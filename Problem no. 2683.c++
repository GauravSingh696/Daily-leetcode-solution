class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Xor = 0;

        for(auto it : derived) {
            Xor ^= it;
        }

        return Xor == 0;
    }
};
