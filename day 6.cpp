#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c; 
        if (curRow == 0 || curRow == numRows - 1) {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (string row : rows) {
        result += row;
    }

    return result;
}

int main() {
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << convert(s1, numRows1) << endl; 

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << convert(s2, numRows2) << endl;  

    string s3 = "A";
    int numRows3 = 1;
    cout << convert(s3, numRows3) << endl; 

    return 0;
}
