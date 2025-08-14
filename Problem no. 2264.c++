class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> vec = {"999","888","777","666","555","444","333","222","111","000"};

        for(string &str : vec) {
            if(num.find(str) < num.size()) 
                return str;
        }

        return "";
    }
};
