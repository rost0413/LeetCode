/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 10, 2012
 Problem:    Permutations II
 Difficulty:
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a collection of numbers that might contain duplicates, return all
 possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 Solution:
 The instinct way is simply borrow a set to save the permuations. This
 takes O(n^2 * lgn).
 Is there a better solution?

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
	vector<vector<int> > permuteUnique(vector<int> &num) {
	}
};
