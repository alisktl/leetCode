/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

*****************

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000
*/

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) {
        vector<int> tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
    }

    int s1 = nums1.size();
    int s2 = nums2.size();

    int half = (s1 + s2 + 1)/2;

    int left = 0;
    int right = s1;

    while(left <= right) {
        int m1 = left + (right - left)/2;
        int m2 = half - m1;

        int left_max_1 = m1 == 0 ? INT_MIN : nums1[m1-1];
        int left_max_2 = m2 == 0 ? INT_MIN : nums2[m2-1];
        int right_min_1 = m1 == s1 ? INT_MAX : nums1[m1];
        int right_min_2 = m2 == s2 ? INT_MAX : nums2[m2];

        if(left_max_1 > right_min_2) {
            right = m1-1;
        } else if(left_max_2 > right_min_1) {
            left = m1+1;
        } else {
            if((s1+s2)%2 == 1) {
                return (double)max(left_max_1, left_max_2);
            } else {
                return (max(left_max_1, left_max_2) + min(right_min_1, right_min_2))/2.0;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums1{1,2};
    vector<int> nums2{3,4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}