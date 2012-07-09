/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 5, 2012
 Problem:    Median of Two Sorted Arrays
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 There are two sorted arrays A and B of size m and n respectively. Find the
 median of the two sorted arrays. The overall run time complexity should be
 O(log (m+n)).

 Solution:
 First compare the median of the two arrays, say Am and Bm, if Am is larger
 than Bm, then there are at least half of m + n elements that are less than
 Am. It means the overall median must less than or equal to Am. Thus the
 elements that larger than Am are eliminated.
 Repeat the above process until the number of eliminated elements are half
 of m + n;
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
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int i = m;
		int j = n;

		while ((i + j) > (m + n) / 2) {

		}
	}
};
