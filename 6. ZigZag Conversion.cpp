/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

*****************

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Example 3:
Input: s = "A", numRows = 1
Output: "A"
*/

#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    string result = "";

    if(numRows == 1) {
        return s;
    }
        
    int n = s.length();

    int gap = numRows + (numRows - 2);

    int numCols = (int)ceil(n/(double)gap);
        
    vector< vector<char> > rows(gap);

    for(int i = 0; i < gap; i++) {
        rows[i].resize(numCols);
    }

    for(int i = 0; i < n; i++) {
        rows[i%gap][i/gap] = s[i];
    }

    int col = 0;
    int index = 0;
    char curChar;

    for(int rowIndex = 0; rowIndex < numRows; rowIndex++) {
        for(int colIndex = 0; colIndex < rows[rowIndex].size(); colIndex++) {
            index = gap * colIndex + rowIndex;
            col = colIndex+1;

            curChar = rows[rowIndex][colIndex];

            if(curChar != '\u0000') {
                result += curChar;
            }

            int newRowIndex = gap*col-index;

            if(newRowIndex > numRows - 1 && newRowIndex < gap) {
                curChar = rows[newRowIndex][colIndex];

                if(curChar != '\u0000') {
                    result += curChar;
                }
            }
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int numRows;

    cin >> s;
    cin >> numRows;

    cout << convert(s, numRows) << endl;

    return 0;
}