/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

*****************

Example 1:
Input: s = "babad"
Output: "bab"

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"
*/

#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    int start_idx = 0, end_idx = 0;
    int left = (n)/2;
    int right = left;

    int i = left, j = left;

    bool pure = true;

    if(n < 2) {
        return s;
    }

    while(left >= 0 || right <= n-1) {
        if(i > 0 && j < n-1 && s[i-1] == s[j+1]) {
            if(s[j+1] != s[j]) {
                pure = false;
            }
            --i;
            ++j;

            if(end_idx - start_idx < j - i) {
                start_idx = i;
                end_idx = j;
            }
        } else if(pure && i > 0 && s[i-1] == s[i]) {
            --i;

            if(end_idx - start_idx < j - i) {
                start_idx = i;
                end_idx = j;
            }
        } else if(pure && j < n-1 && s[j] == s[j+1]) {
            ++j;

            if(end_idx - start_idx < j - i) {
                start_idx = i;
                end_idx = j;
            }
        } else {
            if(left == 0) {
                left = -1;
            }

            if((end_idx - start_idx + 1)/2 > left) {
                left = -1;
            }

            if((end_idx - start_idx + 1)/2 > n-right) {
                right = n+1;
            }

            if(left > 0) {
                --left;
                i = left;
                j = left;
                pure = true;
            } else if(right < n) {
                ++right;
                i = right;
                j = right;
                pure = true;
            }
        }
    }

    return s.substr(start_idx, end_idx - start_idx + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}