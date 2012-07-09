/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 7, 2012
 Problem:    Minimum Path Sum
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a m x n grid filled with non-negative numbers, find a path from top
 left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.
 Solution:
 dp
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
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		int n = grid[0].size();
		int f[m][n];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) {
					f[i][j] = grid[i][j];
				} else if (i == 0 && j != 0) {
					f[i][j] = f[i][j - 1] + grid[i][j];
				} else if (i != 0 && j == 0) {
					f[i][j] = f[i - 1][j] + grid[i][j];
				} else {
					f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
				}
			}
		}

		return f[m - 1][n - 1];
	}
};
