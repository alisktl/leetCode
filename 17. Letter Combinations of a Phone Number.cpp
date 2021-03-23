/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*****************

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> letterCombinations(string digits) {
    unordered_map<short, vector<char> > chars;
    chars['2'] = vector<char> {'a', 'b', 'c'};
    chars['3'] = vector<char> {'d', 'e', 'f'};
    chars['4'] = vector<char> {'g', 'h', 'i'};
    chars['5'] = vector<char> {'j', 'k', 'l'};
    chars['6'] = vector<char> {'m', 'n', 'o'};
    chars['7'] = vector<char> {'p', 'q', 'r', 's'};
    chars['8'] = vector<char> {'t', 'u', 'v'};
    chars['9'] = vector<char> {'w', 'x', 'y', 'z'};

    vector<string> result;

    if(digits.size() == 0) return result;

    if(digits.size() == 1) {
        for(int i = 0; i < chars[digits[0]].size(); i++) {
            string s = "";
            result.emplace_back(   s+chars[digits[0]][i]   );
        }
    } else {
        vector<string> v = letterCombinations(digits.substr(1));

        for(int i = 0; i < chars[digits[0]].size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                result.emplace_back(    chars[digits[0]][i] + v[j]    );
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string digits;
    cin >> digits;

    vector<string> result = letterCombinations(digits);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}