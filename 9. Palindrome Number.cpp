/*
9. Palindrome Number

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

*****************

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false

Example 3:
Input: x = 10
Output: false

Example 4:
Input: x = -101
Output: false
*/

#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    } else if(x == 0) {
        return true;
    }

    int n = (int) log10(x) + 1;
    int power = (int) pow(10, n-1);

    while(n > 0) {
        int left = x/power;
        int right = x%10;

        if(left != right) {
            return false;
        }
            
        x -= left * power;
        x /= 10;

        n-=2;
        power /= 100;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}
