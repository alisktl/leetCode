/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

*****************

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    if(s.size()%2 == 1) return false;

    unordered_map<char, char> symbol_map;
    symbol_map[')'] = '(';
    symbol_map['}'] = '{';
    symbol_map[']'] = '[';

    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            }

            char c = st.top();
            st.pop();

            if(symbol_map.find(s[i]) == symbol_map.end()) return false;

            if(symbol_map[s[i]] != c) return false;
        }
    }

    if(st.size() > 0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    bool is_valid = isValid(s);

    if(is_valid) cout << "true\n";
    else cout << "false\n";
}