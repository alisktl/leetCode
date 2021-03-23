/*
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

*****************

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int sum = 1e6;
    vector<short> nums_2;
    unordered_map<short, short> freq_map;

    for(int i = 0; i < nums.size(); i++) {
        if(freq_map.find(nums[i]) != freq_map.end()) {
            int _freq = freq_map[nums[i]];
            if(_freq < 3) {
                nums_2.emplace_back(nums[i]);
                ++freq_map[nums[i]];
            }

            continue;
        }

        nums_2.emplace_back(nums[i]);
        freq_map[nums[i]] = 1;
    }

    sort(nums_2.begin(), nums_2.end());

    int left = 1, right = nums_2.size()-1;

    for(int i = 0; i < nums_2.size()-1; i++) {
        left = i+1;
        right = nums_2.size()-1;

        while(left < right) {
            int new_sum = nums_2[left] + nums_2[right] + nums_2[i];

            if(abs(new_sum - target) < abs(sum - target)) {
                sum = new_sum;
            }

            if(new_sum < target) ++left;
            else --right;
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = threeSumClosest(nums, target);

    cout << result << "\n";

    return 0;
}