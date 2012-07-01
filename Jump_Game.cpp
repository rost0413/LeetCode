/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jun 29, 2012
 Problem:    Jump Game
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index
 of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.

 A = [3,2,1,0,4], return false.
 Solution:
 Code is simple to read.
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
	bool canJump(int A[], int n) {
		int i = 0;
		int range = 0;

		while (i <= range) {
			if (range >= n - 1){
				return true;
			}
			range = max(range, i + A[i]);
			i++;
		}

		return false;
	}
};
