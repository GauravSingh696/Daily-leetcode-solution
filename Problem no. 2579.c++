// approach 1st

class Solution {
public:
    long long coloredCells(int n) {
        long long count = 1;
        long long cell = 2;

        while(cell <= n) {
            count += 4 * (cell-1);
            cell++;
        }

        return count;
    }
};



// approach 2nd

class Solution {
public:
    long long coloredCells(int n) {
        return (1 + 4 * (((n-1)*(long long)n)/2));
    }
};
