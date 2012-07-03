/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 2, 2012
 Problem:    Longest Common Prefix
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Write a function to find the longest common prefix string amongst an array of
 strings.
 Solution:
 Simple.
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
	string commonPrefix(string a, string b) {
		int len = min(a.length(), b.length());
		int i;
		for (i = 0; i < len; i++) {
			if (a[i] != b[i])
				break;
		}
		return a.substr(0, i);
	}
	string binary(int s, int t, vector<string>& strs) {
		if (s > t)
			return "";
		if (s == t)
			return strs[s];

		return commonPrefix(binary(s, (s + t) / 2, strs),
				binary((s + t) / 2 + 1, t, strs));
	}
	string longestCommonPrefix(vector<string> &strs) {

		return binary(0, strs.size() - 1, strs);
	}
};
