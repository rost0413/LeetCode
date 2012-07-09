/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 2, 2012
 Problem:    Longest Palindromic Substring
 Difficulty:
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string S, find the longest palindromic substring in S. You may assume
 that the maximum length of S is 1000, and there exists one unique longest
 palindromic substring.

 Solution:
 Find the longest substring of s and the reversion of s. And find the longest
 common substring with dynamic programmming (O(n^2)). For the longest common substring
 problem, it can also be solved by suffix tree (O(2n)).
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
	string longestPalindrome(string s) {

	}
};
