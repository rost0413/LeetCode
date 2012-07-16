/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 12, 2012
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a sorted array, remove the duplicates in place such that each element
 appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with
 constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2].
 Solution:

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
	int removeDuplicates(int A[], int n) {
		int i, j;
		for (i = 1, j = 1; i < n; i++) {
			if (A[i] != A[i - 1]) {
				A[j] = A[i];
				j++;
			}
		}
		return (n == 0 ? 0 : j);
	}
};
