class Spreadsheet {
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet.resize(rows, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        string row = cell.substr(1);
        char col = cell[0];
        
        sheet[stoi(row)-1][col-'A'] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx-1);
        string right = formula.substr(idx+1);
        int val1 = 0, val2 = 0;
                
        if(isdigit(left[0])) {
            val1 = stoi(left);
        } else {
            string row = left.substr(1);
            char col = left[0];
            val1 = sheet[stoi(row)-1][col-'A'];
        }
        
        if(isdigit(right[0])) {
            val2 = stoi(right);
        } else {
            string row = right.substr(1);
            char col = right[0];
            val2 = sheet[stoi(row)-1][col-'A'];
        }

        return val1+val2;
    }
};
