/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 3, 2012
 Problem:    Longest Valid Parentheses
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string containing just the characters '(' and ')', find the length of
 the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses substring is
 "()()", which has length = 4.

 Solution:
 Borrow a stack to simulate the parentheses. Push into stack when encounter a '(',
 and pop from stack when encounter a ')' (scan from left to right). To find the
 longest valid parentheses, we need to think about the property of it. For every
 VP, the stack operation must end with top 0, any other top location will result
 in invalid parentheses. And LVP maybe surround with any characters, and the stack
 operation for these surrounding characters must be invalid.

 Another important property of this problem is that, the invalid characters must
 be located at the beginning or/and the end of the string. For example, given a
 string like, "...())((...", (... means unknown number of '(' and ')') we cann't
 determine whether the whole string is valid or not from only the inside few
 characters. Thus traverse from both directions with stack operations often remove
 the impact of invalid surrounding characters.

 What am I saying.
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
	int longestValidParentheses(string s) {
		int stack = 0;
		int continuous = 0;
		int result = 0;

		for (int i = 0; i < s.length(); i++) {
			continuous++;
			stack = (s[i] == '(' ? stack + 1 : stack - 1);
			if (stack == 0) {
				result = max(result, continuous);
			} else if (stack < 0) {
				stack = 0;
				continuous = 0;
			}
		}

		continuous = 0;
		stack = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			continuous++;
			stack = (s[i] == ')' ? stack + 1 : stack - 1);
			if (stack == 0) {
				result = max(result, continuous);
			} else if (stack < 0) {
				stack = 0;
				continuous = 0;
			}
		}
		return result;
	}
};
