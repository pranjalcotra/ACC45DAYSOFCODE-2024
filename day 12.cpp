#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num) {

    vector<pair<int, string>> roman_map = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string roman_numeral = "";

    for (auto& pair : roman_map) {
        int value = pair.first;
        string symbol = pair.second;
 
        while (num >= value) {
            roman_numeral += symbol;
            num -= value;
        }
    }
    
    return roman_numeral;
}

int main() {
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "Roman numeral for " << num1 << " is " << intToRoman(num1) << endl;
    cout << "Roman numeral for " << num2 << " is " << intToRoman(num2) << endl;
    cout << "Roman numeral for " << num3 << " is " << intToRoman(num3) << endl;

    return 0;
}
