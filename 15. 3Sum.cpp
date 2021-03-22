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
    vector<int> nums_1;
    vector<int> nums_2;

    if(nums.size() < 3) return result;

    unordered_map<int, short> freq_map;
    unordered_map<string, bool> cache;

    for(int i = 0; i < nums.size(); i++) {
        if(freq_map.find(nums[i]) != freq_map.end()) {
            int _freq = freq_map[nums[i]];
            if(_freq < 3) {
                if(_freq == 1) nums_2.emplace_back(nums[i]);

                ++freq_map[nums[i]];
            }

            continue;
        }

        nums_1.emplace_back(nums[i]);
        freq_map[nums[i]] = 1;
    }

    sort(nums_1.begin(), nums_1.end());
    sort(nums_2.begin(), nums_2.end());

    for(int i = 0; i < nums_1.size(); i++) {
        for(int j = i+1; j < nums_1.size(); j++) {
            int _add = -(nums_1[i] + nums_1[j]);
            
            if(_add < nums_1[j]) continue;

            if(freq_map.find(_add) != freq_map.end()) {
                if(cache.find(to_string(nums_1[i]) + '.' + to_string(nums_1[j]) + '.' + to_string(_add)) == cache.end()) {
                    if(nums_1[i] != _add && nums_1[j] != _add) {
                        
                        result.emplace_back(vector<int> {nums_1[i], nums_1[j], _add});
                        cache[to_string(nums_1[i]) + '.' + to_string(nums_1[j]) + '.' + to_string(_add)] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < nums_2.size(); i++) {
        if(freq_map.find(-(nums_2[i] * 2)) != freq_map.end()) {
            int _add = -(nums_2[i] * 2);
            if(cache.find(to_string(nums_2[i]) + '.' + to_string(nums_2[i]) + '.' + to_string(_add)) == cache.end()) {
                if((nums_2[i] != _add) ||
                    (nums_2[i] == _add && freq_map[_add] >= 3)) {

                    result.emplace_back(vector<int> {nums_2[i], nums_2[i], _add});
                    cache[to_string(nums_2[i]) + '.' + to_string(nums_2[i]) + '.' + to_string(_add)] = true;
                }
            }
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
