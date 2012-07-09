/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 6, 2012
 Problem:    Merge Sorted Array
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space to hold additional elements from B.
 The number of elements initialized in A and B are m and n respectively.

 Solution:
 This problem should be solved without a third array.
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
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;

		while (i >= 0 && j >= 0) {
			A[k--] = (A[i] > B[j] ? A[i--] : B[j--]);
		}
		while (i >= 0) {
			A[k--] = A[i--];
		}
		while (j >= 0) {
			A[k--] = B[j--];
		}
	}
};
