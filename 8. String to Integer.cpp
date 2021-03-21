/*
8. String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
6. Return the integer as the final result.

Note:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

*****************

Example 1:
Input: s = "42"
Output: 42

Example 2:
Input: s = "   -42"
Output: -42

Example 3:
Input: s = "4193 with words"
Output: 4193

Example 4:
Input: s = "words and 987"
Output: 0

Example 5:
Input: s = "-91283472332"
Output: -2147483648
*/

#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s) {
    bool finish = false;
    bool reachedNumber = false;
    int n = s.length();
    int result = 0;
    int sign = 1;

    int index = 0;

    char char0 = '0';
    char char9 = '9';

    char curChar;

    while(!finish) {
        if(index >= n) {
            break;
        }

        curChar = s[index];

        if(char0 <= curChar && curChar <= char9) {
            int digit = (curChar-char0);

            if(result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX%10)) {
                return INT_MAX;
            }

            if(result < INT_MIN/10 || (result == INT_MIN/10 && -digit < INT_MIN%10)) {
                return INT_MIN;
            }

            result = result * 10 + sign*digit;

            reachedNumber = true;
        } else if((curChar == '-' || curChar == '+') && !reachedNumber) {
            if(index + 1 < n) {
                char nextChar = s[index+1];

                if(nextChar < char0 || char9 < nextChar) {
                    return 0;
                }
            }

            if(curChar == '-') {
                sign = -1;
            }
        } else if(reachedNumber || curChar != ' ') {
            finish = true;
        }

        ++index;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    cout << myAtoi(s) << "\n";
    return 0;
}
