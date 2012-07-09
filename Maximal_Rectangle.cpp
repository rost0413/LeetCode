/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 3, 2012
 Problem:    Maximal Rectangle
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 containing all ones and return its area.

 Solution:
 The idea comes from
 http://www.drdobbs.com/database/the-maximal-rectangle-problem/184410529 .
 Traverse from left-top corner extends to the right-bottom corner, try to find
 the maximal rectangle with fixed left-top point. The naive method takes O(m^2 * n^2)
 time complexity. It can be improved by following optimizations.
 1. Pre-compute the consecutive 1' in the scanning direction. This optimization
 improves time complexity to O(m^2 * n).
 Before:
 0 0 0 0
 1 1 1 0
 1 1 0 0
 0 1 1 0
 After:
 0 0 0 0
 3 2 1 0
 2 1 0 0
 0 2 1 0

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
	int n;
	int m;
	int **mat;
	int maxRectangle(int lx, int ly) {
		int area = 0;
		int rx = lx;
		int ry = ly + mat[rx][ly] - 1;

		while (rx < n - 1 && mat[rx][ly]) {
			area = max(area, (ry - ly + 1) * (rx - lx + 1));
			rx++;
			ry = min(ry, ly + mat[rx][ly] - 1);
		}

		return max(area, (ry - ly + 1) * (rx - lx + 1));
	}
	int maximalRectangle(vector<vector<char> > &matrix) {
		int result = 0;

		n = matrix.size();
		m = (n != 0 ? matrix[0].size() : 0);
		mat = new int *[n];
		for (int i = 0; i < n; i++) {
			mat[i] = new int[m];
		}

		// pre-compute
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (matrix[i][j] == '0') {
					mat[i][j] = 0;
				} else {
					mat[i][j] = (j < m - 1 ? mat[i][j + 1] + 1 : 1);
				}
			}
		}

		// traverse from left-top to right-bottom
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j]){
					result = max(result, maxRectangle(i, j));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			delete[] mat[i];
		}
		delete[] mat;
		return result;
	}
};
