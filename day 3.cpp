#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman_values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int prev_value = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        int current_value = roman_values[s[i]];

        if (current_value < prev_value) {
            total -= current_value;
        } else {

            total += current_value;
        }

        prev_value = current_value;
    }

    return total;
}

int main() {
    cout << romanToInt("III") << endl;  
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl; 

    return 0;
}

