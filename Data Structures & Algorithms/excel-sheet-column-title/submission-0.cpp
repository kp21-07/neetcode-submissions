class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output = "";
        while (columnNumber > 0) {
            output = string(1, 'A' + ((columnNumber - 1) % 26)) + output;
            columnNumber = (columnNumber - 1) / 26;
        }
        return output;
    }
};

        