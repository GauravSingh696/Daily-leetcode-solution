class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string temp;
        string result;

        while(ss >> temp) {
            k--;
            result = result + temp + " ";

            if(k==0)
                break;
        }

        result.pop_back();

        return result;
    }
};
