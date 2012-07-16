/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 11, 2012
 Problem:    Regular Expression Matching
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Implement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true

 Solution:
 The basic idea is recursion. The boundry condition is not easy.
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
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {
			return *s == '\0';
		}
		if (*(p + 1) == '*') {
			while ((*p == *s) || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p + 2)) {
					return true;
				}
				s++;
			}
			return isMatch(s, p + 2);
		} else if ((*p == '.' && *s != '\0') || *s == *p) {
			return isMatch(s + 1, p + 1);
		}
		return false;
	}
};
