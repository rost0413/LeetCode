/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 12, 2012
 Problem:    Remove Duplicates from Sorted Array II
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array A = [1,1,1,2,2,3],

 Your function should return length = 5, and A is now [1,1,2,2,3].
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
		int len = 0;
		for (int i = 0, count = 0, k = 0; i < n; i++) {
			count = (i == 0 || A[i] == A[i - 1] ? count + 1 : 1);
			if (count <= 2) {
				A[k] = A[i];
				len++;
				k++;
			}
		}
		return len;
	}
};
