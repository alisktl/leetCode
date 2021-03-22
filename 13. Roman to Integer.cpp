/*
13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5

X             10
L             50
C             100

D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

* I can be placed before V (5) and X (10) to make 4 and 9. 
* X can be placed before L (50) and C (100) to make 40 and 90. 
* C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

*****************

Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "IV"
Output: 4

Example 3:
Input: s = "IX"
Output: 9

Example 4:
Input: s = "LVIII"
Output: 58

Example 5:
Input: s = "MCMXCIV"
Output: 1994
*/

#include <iostream>

using namespace std;

int romanToInt(string s) {
    int result = 0;

    while(s.size() != 0) {
        if(s[0] == 'M') result += 1000, s = s.substr(1);
        else if(s[0] == 'C' && s[1] == 'M') result += 900, s = s.substr(2);
        else if(s[0] == 'D') result += 500, s = s.substr(1);
        else if(s[0] == 'C' && s[1] == 'D') result += 400, s = s.substr(2);
        else if(s[0] == 'C') result += 100, s = s.substr(1);

        else if(s[0] == 'X' && s[1] == 'C') result += 90, s = s.substr(2);
        else if(s[0] == 'L') result += 50, s = s.substr(1);
        else if(s[0] == 'X' && s[1] == 'L') result += 40, s = s.substr(2);
        else if(s[0] == 'X') result += 10, s = s.substr(1);

        else if(s[0] == 'I' && s[1] == 'X') result += 9, s = s.substr(2);
        else if(s[0] == 'V') result += 5, s = s.substr(1);
        else if(s[0] == 'I' && s[1] == 'V') result += 4, s = s.substr(2);
        else if(s[0] == 'I') result += 1, s = s.substr(1);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    cout << romanToInt(s) << "\n";

    return 0;
}
