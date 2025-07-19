class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(), f.end());
        vector<string> result;

        for (auto &folder : f) {
            if (result.empty() || folder.find(result.back() + "/") != 0) {
                result.push_back(folder);
            }
        }

        return result;
    }
};
