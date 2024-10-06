// 06-10-2024

class Solution {
public:
    bool areSentencesSimilar(string sent1, string sent2) {
        if(sent1.size() < sent2.size()) {
            swap(sent1 , sent2);
        }

        deque<string> d1, d2;
        stringstream ss1(sent1);
        stringstream ss2(sent2);
        string temp;

        while(ss1 >> temp) {
            d1.push_back(temp);
        }

        while(ss2 >> temp) {
            d2.push_back(temp);
        }

        while(!d1.empty() && !d2.empty() && d1.front() == d2.front()) {
            d1.pop_front();
            d2.pop_front();
        }

        while(!d1.empty() && !d2.empty() && d1.back() == d2.back()) {
            d1.pop_back();
            d2.pop_back();
        }

        return d2.empty();

    }
};
