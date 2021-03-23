/*
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

*****************

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> nums_2;

    if(nums.size() < 3) return result;

    unordered_map<int, short> freq_map;

    for(int i = 0; i < nums.size(); i++) {
        if(freq_map.find(nums[i]) != freq_map.end()) {
            int _freq = freq_map[nums[i]];
            if(_freq < 3) {

                ++freq_map[nums[i]];
            }

            continue;
        }

        nums_2.emplace_back(nums[i]);
        freq_map[nums[i]] = 1;
    }

    sort(nums_2.begin(), nums_2.end());

    int left = 0, right = nums_2.size()-1;

    if(freq_map.find(0) != freq_map.end()) {
        if(freq_map[0] >= 3) result.emplace_back(vector<int> {0, 0, 0});
    }

    while(left < right) {
        if(nums_2[left] <= nums_2[right]) {
            int _add = -(nums_2[left] + nums_2[right]);

            if(nums_2[left] <= _add && _add <= nums_2[right]) {
                if(freq_map.find(_add) != freq_map.end()) {
                    int _freq = freq_map[_add];
                    if((nums_2[left] != _add && _add != nums_2[right]) ||
                        (nums_2[left] == _add && _add != nums_2[right] && _freq >= 2) ||
                        (nums_2[left] != _add && _add == nums_2[right] && _freq >= 2)) {

                        result.emplace_back(vector<int> {nums_2[left], _add, nums_2[right]});
                    }
                }
            }
        }

        if(left >= right-1) {
            ++left;
            right = nums_2.size()-1;
        } else {
            --right;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    cout << '[';
    for(int i = 0; i < result.size(); i++) {
        cout << '[' << result[i][0] << ',' << result[i][1] << ',' << result[i][2] << ']';

        if(i + 1 < result.size()) cout << ',';
    }
    cout << "]\n";
}
