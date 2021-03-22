/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

*****************

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2
*/

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;

    int left_idx = 0;
    int right_idx = height.size()-1;

    while(left_idx < right_idx) {
        int area = min(height[left_idx], height[right_idx]) * (right_idx - left_idx);

        if(max_area < area) max_area = area;

        if(height[left_idx] < height[right_idx]) left_idx++;
        else right_idx--;
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << maxArea(heights) << "\n";
    return 0;
}


