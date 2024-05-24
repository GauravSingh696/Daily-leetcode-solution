// 24-05-2024

class Solution {
public:
    int n;
    int max_score;

    void solve(int i, vector<int> &score, vector<string> &words, int curr_score, vector<int> &freq)
    {
        max_score = max(max_score, curr_score);

        if(i >= n)
            return ;
        
        vector<int> temp = freq;
        int j = 0;
        int temp_score = 0;

        while(j < words[i].size())
        {
            char ch = words[i][j];

            temp[ch-'a']--;
            temp_score += score[ch-'a'];

            if(temp[ch-'a'] < 0)
                break;
            
            j++;
        }

        if(j == words[i].length())
        {
            solve(i+1, score, words, curr_score + temp_score, temp);
        }

        solve(i+1, score, words, curr_score, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);

        for(char &ch : letters)
        {
            freq[ch-'a']++;
        }

        max_score = INT_MIN;
        n = words.size();

        solve(0, score, words, 0, freq);

        return max_score;
    }
};
