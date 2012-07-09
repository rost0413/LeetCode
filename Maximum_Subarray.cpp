/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 5, 2012
 Problem:    Maximum Subarray
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Find the contiguous subarray within an array (containing at least one number)
 which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 Solution:
 DP.
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
	int maxSubArray(int A[], int n) {
		int result = A[0];
		int sum = A[0];

		for (int i = 1; i < n; i++) {
			sum= max(A[i], sum + A[i]);
			result = max(sum, result);
		}

		return result;
	}
};
