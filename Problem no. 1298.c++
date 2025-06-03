class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& found_boxes) {
        if(visited.count(box))
            return 0;
        
        if(status[box] == 0) {
            found_boxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollected = candies[box];

        for(auto &insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited, found_boxes);
        }

        for(auto &box_key : keys[box]) {
            status[box_key] = 1;

            if(found_boxes.count(box_key)) {
                candiesCollected += dfs(box_key, status, candies, keys, containedBoxes, visited, found_boxes);
            }
        }

        return candiesCollected;
    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candies_collected = 0;
        unordered_set<int> visited;
        unordered_set<int> found_boxes;

        for(auto &box : initialBoxes) {
            candies_collected += dfs(box, status, candies, keys, containedBoxes, visited, found_boxes);
        }

        return candies_collected;
    }
};
