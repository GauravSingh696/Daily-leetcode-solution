// approach 1

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
        
        vector<int> ans;
        for (auto& query : queries) {
            sort(query.begin(), query.end());
            int left = query[0], right = query[1];
            int index = left;
            
            if (right == nge[left] || heights[right] > heights[left] || right == left) {
                ans.push_back(right);
            } else if (nge[left] == -1 || nge[right] == -1) {
                ans.push_back(-1);
            } else {
                int ind = max(nge[left], nge[right]);
                if (heights[ind] > heights[left] && heights[ind] > heights[right]) {
                    ans.push_back(ind);
                } else {
                    while (ind != -1 && (heights[ind] < heights[left] || heights[ind] < heights[right])) {
                        ind = nge[ind];
                    }
                    if (ind != -1 && heights[ind] > heights[left] && heights[ind] > heights[right]) {
                        ans.push_back(ind);
                    } else {
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};


// approach 2 (TLE)

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        vector<int> res(q.size(),-1);

        for(int i=0;i<q.size();i++) {
            int a = q[i][0];
            int b = q[i][1];

            if(a==b) {
                res[i] = b;
                continue;
            }

            cout<<a<<" "<<b<<endl;

            if(a<b) {
                if(h[a] < h[b]) {
                    res[i] = b;
                    continue;
                }

                int cmp = h[a];
                b++;

                while(b<h.size() && cmp >= h[b])
                    b++;
                
                if(b==h.size())
                    continue;
                
                res[i] = b;
            }

            else {
                if(h[b] < h[a]) {
                    res[i] = a;
                    continue;
                }

                int cmp = h[b];
                a++;

                while(a<h.size() && cmp >= h[a])
                    a++;
                
                if(a==h.size())
                    continue;
                
                res[i] = a;
            }
        }

        return res;
    }
};
