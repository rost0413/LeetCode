/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jun 29, 2012
 Problem:    Jump Game II
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given an array of non-negative integers, you are initially positioned at the
 first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Your goal is to reach the last index in the minimum number of jumps.

 For example:
 Given array A = [2,3,1,1,4]

 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index
 0 to 1, then 3 steps to the last index.)
 Solution:
 To avoid TLE, optimize.
 */
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		int steps[n];
		int limit;

		steps[0] = 0;
		limit = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i + A[i] > limit) {
				if (i + A[i] >= n - 1) {
					return steps[i] + 1;
				}
				for (int j = limit + 1; j <= i + A[i] && j < n; j++) {
					steps[j] = steps[i] + 1;
				}
				limit = i + A[i];
			}
		}

		return steps[n - 1];
	}
};
