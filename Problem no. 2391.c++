class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<pair<int,int>> glass, paper, metal;

        for(int i=0;i<n;i++) {
            int g = count(garbage[i].begin(), garbage[i].end(), 'G');
            int p = count(garbage[i].begin(), garbage[i].end(), 'P');
            int m = count(garbage[i].begin(), garbage[i].end(), 'M');

            int v1 = g>0 ? i : -1;
            int v2 = p>0 ? i : -1;
            int v3 = m>0 ? i : -1;
            
            if(v1 >= 0)
                glass.push_back({g, v1});
            
            if(v2 >= 0)
                paper.push_back({p, v2});
            
            if(v3 >= 0)
                metal.push_back({m, v3});
        }

        int glass_garbage = 0;
        int paper_garbage = 0;
        int metal_garbage = 0;
        
        // glass garbage
        if(!glass.empty()) {
            int n1 = glass.size()-1;

            for(auto &it : glass) {
                glass_garbage += it.first;
            }

            glass_garbage += accumulate(travel.begin(), travel.begin() + glass[n1].second, 0);
        }

        // paper garbage
        if(!paper.empty()) {
            int n2 = paper.size()-1;

            for(auto &it : paper) {
                paper_garbage += it.first;
            }

            paper_garbage += accumulate(travel.begin(), travel.begin() + paper[n2].second, 0);
        }

        // metal garbage
        if(!metal.empty()) {
            int n3 = metal.size()-1;

            for(auto &it : metal) {
                metal_garbage += it.first;
            }

            metal_garbage += accumulate(travel.begin(), travel.begin() + metal[n3].second, 0);
        }

        return glass_garbage + paper_garbage + metal_garbage;
    }
};
