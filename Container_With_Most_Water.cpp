/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 27, 2012
Problem:    Container With Most Water
Difficulty: Hard
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given n non-negative integers a1, a2, ..., an, where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms
a container, such that the container contains the most water.
Note: You may not slant the container.

Solution:
Search from left and right using two indices, say x0 and y0. x moves from left to right,
and y moves from right to left. The volume is min(height(x), height(y)) * (y - x).
Search for larger volume than the original volume.
When we decide which index to move and move to where, we follow two principles:
1. Suppose we move from x to right, then the next index x' must have height(x') > height(x).
If height(x') <= height(x), the volume only becomes smaller because the the values of
both (y - x) and min(height(x), height(y) are becomes smaller. Since (y - x) always
getting smaller, the volume will have chance to get larger only when height(x') > height(x).
2. When decide which index (x or y) to move, we always move the index with shorter height.
Suppose height(x) < height(y) and we move y left to y' which height(y') > height(y), the
volume is always getting smaller because (y - x) is smaller and min(height(x), height(y))
is determined by height(x). The volume has chance to get larger when we move x to right,
because the value of min(height(x), height(y)) is getting larger. If height(x) == height(y),
then we have to move both x and y in order to make volume larger.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int result = 0;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            result = max(area, result);
            if (height[i] <= height[j]) {
                int pi = height[i];
                i++;
                while (height[i] <= pi && i < j)
                    i++;
            }
            else {
                int pj = height[j];
                j--;
                while (height[j] <= pj && i < j)
                    j--;
            }
        }

        return result;
    }
};




