/*
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

1. '.' Matches any single character.​​​​
2. '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

*****************

Example 1:
Input: s = "aa", p = "a"
Output: false

Example 2:
Input: s = "aa", p = "a*"
Output: true

Example 3:
Input: s = "ab", p = ".*"
Output: true

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    bool A[s.size() + 1][p.size() + 1];

    for(int i = 0; i <= s.size(); i++) {
        for(int j = 0; j <= p.size(); j++) {
            A[i][j] = false;
        }
    }

    A[s.size()][p.size()] = true;

    for(int i = s.size(); i >= 0; i--) {
        for(int j = p.size()-1; j >= 0; j--) {
            bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

            if(j+1 < p.size() && p[j+1] == '*') {
                A[i][j] = A[i][j+2] || match && A[i+1][j];
            } else {
                A[i][j] = match && A[i+1][j+1];
            }
        }
    }

    return A[0][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;

    bool match = isMatch(s, p);

    if(match) cout << "true\n";
    else cout << "false\n";

    return 0;
}
