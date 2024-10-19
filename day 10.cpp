#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matchingBracket = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            
            if (st.empty() || st.top() != matchingBracket[c]) {
                return false;
            }
            st.pop(); 
        }
    }
    
    return st.empty();
}

int main() {
    string s;

    cout << "Enter a string of brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
