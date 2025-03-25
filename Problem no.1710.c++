class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>> pq;

        for(auto &it : boxTypes) {
            pq.push({it[1] , it[0]});
        }

        int result = 0;

        while(!pq.empty()) {
            int box = pq.top().second;
            int units = pq.top().first;

            if(box <= truckSize) {
                truckSize -= box;
                result += box * units;
            }

            else {
                result += truckSize * units;
                break;
            }

            if(truckSize <= 0)
                break;
            
            pq.pop();
        }

        return result;
    }
};
