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
 This is the faster version of maximal rectangle program with another optimaization.
 It improves the time compelxity to O(n^m).

 Exploiting Structure
 Caching or remembering intermediate results is a general technique that applies
 to a wide variety of algorithms. It's also a technique that can often easily be
 integrated into existing algorithms. Ultimately, though, most optimal algorithms
 depend on the more unique features of a problem, and the maximal rectangle problem
 is no exception.

 To find some additional structure in the problem, consider Figure 4, which depicts
 the cache c as a sort of profile of ones to the right of the current column. The
 previous algorithm examined every rectangle of ones that fits in that profile.
 However, some of these rectangles aren't as worth examining as others. For example,
 the dashed rectangle in Figure 4 is inside the profile described by the current
 contents of the cache, but there are larger rectangles in the profile which enclose
 the dashed one. My goal then is to examine only those rectangles that are inside
 the profile, but not contained by another rectangle in that profile. These rectangles
 were drawn in a slightly thicker line in the left half of Figure 4; the solution
 rectangle (in red) is one of these interesting rectangles.

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
		int width;
		for (int i = 0; i < n; i++) {
			width = 0;
			for (int j = 0; j < m; j++) {
				if (!mat[i][j]) {
					width = 0;
					continue;
				}
				if (i == 0 || mat[i][j] > mat[i - 1][j]) {
					width = mat[i][j];
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
