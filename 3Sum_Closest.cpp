/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 19, 2012
Problem:    3 Sum Closest
Difficulty: medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given an array S of n integers, find three integers in S such that the sum is closest
to a given number, target. Return the sum of the three integers. You may assume that
each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Solution:
The idea is similiar with 3 Sum problem. Use additional variables to store the minimal
difference between the sum of 3 and the target. This method is O(n^2) as the 3 Sum
problem.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int global_close = INT_MAX;
        int local_close = INT_MAX;
        int i, j, k, sum;

        sort(num.begin(), num.end());

        for (i = 0; i < n; i++) {
            j = 0;
            k = n - 1;

            while (j < k) {
                if (j == i) {
                    j++;
                    continue;
                }
                if (k == i) {
                    k--;
                    continue;
                }
                sum = num[i] + num[j] + num[k];
                // FIXME: local_close == INT_MAX maybe cause unexpected boundary problem.
                // A better solution can be used.
                if (abs(sum - target) < abs(local_close - target) || local_close == INT_MAX) {
                    local_close = sum;
                }
                if (sum - target < 0) {
                    j++;
                }
                else if (sum - target > 0) {
                    k--;
                }
                else {
                    return sum;
                }
            }
            // FIXME: global_close == INT_MAX maybe cause unexpected boundary problem.
            // A better solution can be used.
            if (abs(global_close - target) > abs(local_close - target) || global_close == INT_MAX) {
                global_close = local_close;
            }
        }

        return global_close;
    }
};
