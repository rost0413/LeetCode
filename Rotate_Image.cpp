/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 15, 2012
 Problem:    Rotate Image
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).

 Follow up:
 Could you do this in-place?

 Solution:
 First swap left half and right half, then swap left top half with right bottom
 half.
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
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
			}
		}
	}
};
