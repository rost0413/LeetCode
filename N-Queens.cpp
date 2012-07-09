/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 8, 2012
 Problem:    N-Queens
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 such that no two queens attack each other.
 Given an integer n, return all distinct solutions to the n-queens puzzle.

 Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.

 For example,
 There exist two distinct solutions to the 4-queens puzzle:

 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
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
	vector<vector<string> > result;
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
			vector<string> sol;
			for (int i = 0; i < n; i++) {
				string line(n, '.');
				line[board[i]] = 'Q';
				sol.push_back(line);
			}
			result.push_back(sol);
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
	vector<vector<string> > solveNQueens(int n) {
		board = new int[n];
		for (int i = 0; i < n; i++) {
			board[i] = -1;
		}
		result.clear();
		dfs(0, n);
		return result;
	}
};
