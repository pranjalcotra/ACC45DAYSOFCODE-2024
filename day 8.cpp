#include <bits/stdc++.h>

using namespace std;

int strStr(const string& haystack, const string& needle) {
    if (needle.empty()) {
        return 0;
    }

    int haystackLen = haystack.length();
    int needleLen = needle.length();

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (haystack.substr(i, needleLen) == needle) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << strStr("sadbutsad", "sad") << endl; 
    return 0;
}
