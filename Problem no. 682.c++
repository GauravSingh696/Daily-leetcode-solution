// approach 1        using stack...

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        for (int i = 0; i < operations.size(); i++)
        {

            if(operations[i]=="+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x + y);
            }

            else if(operations[i]=="C") {
                st.pop();
            }

            else if (operations[i] == "D") {
                int x = st.top() * 2;
                st.push(x);
            }

            else
                st.push(stoi(operations[i]));
        }

        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};


// approach 2    using vector...

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int len = operations.size();
        vector<int> temp;

        for(int i=0;i<len;i++)
        {
            if(operations[i]=="C" && !temp.empty())
                temp.pop_back();
            
            else if(operations[i]=="D" && i!=0)
            {
                temp.push_back(2*temp[temp.size()-1]);
            }
                
            
            else if(operations[i]=="+")
            {
                temp.push_back(temp[temp.size()-1]+temp[temp.size()-2]);
            }

            else
            {
                temp.push_back(stoi(operations[i]));
            }
        }

        int result = 0;

        for(int i=0;i<temp.size();i++)
        {
            result += temp[i];
        }

        return result;
    }
};
