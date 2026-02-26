class Solution {
  public:
    void add_one(string& s) {
        int i = s.length();

        while (i >= 0 && s[i] != '0') {
            s[i--] = '0';
        }

        if (i < 0) {
            s = "1" + s;
        } else {
            s[i] = '1';
        }
    }

    int numSteps(string s) {
        int steps = 0;

        while (s.length() > 1) {
            int n = s.length();

            if (s[n - 1] == '0') {
                s.pop_back();
            } else {
                add_one(s);
            }

            steps++;
        }

        return steps;
    }
};
