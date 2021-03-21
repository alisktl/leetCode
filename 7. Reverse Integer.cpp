/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

*****************

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Example 4:
Input: x = 0
Output: 0
*/

#include <iostream>

using namespace std;

int reverse(int x) {
    int reverse = 0;
    
    while(x != 0) {
        int rem = x%10;

        if((reverse > INT_MAX/10) || reverse == INT_MAX/10 && rem > INT_MAX%10) return 0;
        if((reverse < INT_MIN/10) || reverse == INT_MIN/10 && rem < INT_MIN%10) return 0;

        reverse = reverse*10 + rem;
        x /= 10;
    }

    return reverse;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;

    cout << reverse(x) << "\n";

    return 0;
}
