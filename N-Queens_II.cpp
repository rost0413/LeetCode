/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 8, 2012
 Problem:    N-Queens II
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of
 distinct solutions.

 Solution:
 dfs
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
	int result;
	int *board;
public:
	bool feasible(int x, int y, int n) {
		for (int i = 0; i < x; i++) {
			if (board[i] == y || board[i] + x - i == y
					|| board[i] - x + i == y) {
				return false;
			}
		}
		return true;
	}
	void dfs(int dep, int n) {
		if (dep == n) {
			result++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (feasible(dep, i, n)) {
				board[dep] = i;
				dfs(dep + 1, n);
				board[dep] = -1;
			}
		}
	}
	int totalNQueens(int n) {
		board = new int[n];
		for (int i = 0; i < n; i++) {
			board[i] = -1;
		}
		result = 0;
		dfs(0, n);
		return result;
	}
};
