/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 13, 2012
 Problem:    Remove Element
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given an array and a value, remove all instances of that value in place and
 return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond
 the new length.

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
	int removeElement(int A[], int n, int elem) {
		int len = n;
		for (int i = 0, j = 0; i < n; i++) {
			if (A[i] != elem) {
				A[j] = A[i];
				j++;
			} else {
				len--;
			}
		}
		return len;
	}
};
