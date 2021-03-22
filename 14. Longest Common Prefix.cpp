/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*****************

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
*/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int min_length = INT_MAX;

    for(int i = 0; i < strs.size(); i++) {
        if(strs[i].size() < min_length) {
            min_length = strs[i].size();
        }
    }

    if(min_length == 0 || min_length == INT_MAX) {
        return "";
    }

    int count = 0;

    for(int i = 0; i < min_length; i++) {
        char c = strs[0][i];
        bool broken = false;
        for(int j = 1; j < strs.size(); j++) {
            if(c != strs[j][i]) return strs[0].substr(0, count);
        }
        
        ++count;
    }

    return strs[0].substr(0, count);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> strs(n);

    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << longestCommonPrefix(strs) << "\n";
}
