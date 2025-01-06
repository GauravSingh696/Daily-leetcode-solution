class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> idx;
        int n = boxes.size();

        for(int i=0;i<n;i++) {
            if(boxes[i] == '1')
                idx.insert(i);
        }

        vector<int> result;

        for(int i=0;i<n;i++) {
            int sum = 0;

            for(auto it : idx) {
                sum += abs(i - it);
            }

            result.push_back(sum);
        }

        return result;
    }
};
