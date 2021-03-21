/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

*****************

Example 1:
Input: s = "abcabcbb"
Output: 3

Example 2:
Input: s = "bbbbb"
Output: 1

Example 3:
Input: s = "pwwkew"
Output: 3

Example 4:
Input: s = ""
Output: 0
*/

#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int start_idx = 0, max_length = 0;

    map<char, int> char_map;

    for(int i = 0; i < s.length(); i++) {
        map<char, int>::iterator it = char_map.find(s[i]);

        if(it != char_map.end()) {
            if(start_idx < it->second + 1) {
                start_idx = it->second + 1;
            }
        }

        char_map[s[i]] = i;

        if(max_length < i - start_idx + 1) {
            max_length = i - start_idx + 1;
        }
    }

    return max_length;
}

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}