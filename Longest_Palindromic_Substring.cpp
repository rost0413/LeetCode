/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 2, 2012
 Problem:    Longest Palindromic Substring
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string S, find the longest palindromic substring in S. You may assume
 that the maximum length of S is 1000, and there exists one unique longest
 palindromic substring.

 Solution:
 Find the longest substring of s and the reversion of s. And find the longest
 common substring with dynamic programmming (O(nn)). For the longest common substring
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
		int maxl = 0;
		int id = 0;
		for (unsigned i = 0; i < s.size(); i++) {
			int len = 1;
			while ((i + len < s.size()) && (i - len >= 0)
					&& (s[i + len] == s[i - len])) {
				if (len > maxl){
					maxl = len;
					id = i;
				}
				len++;
			}
		}
		return s.substr(id - maxl, 2 * maxl + 1);
	}
};
