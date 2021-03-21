/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*****************

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2);

    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;

                return res;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums{2,7,11,15};
    int target = 9;

    vector<int> res = twoSum(nums, target);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}