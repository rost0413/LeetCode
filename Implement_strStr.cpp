/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jun 28, 2012
 Problem:    Implement strStr()
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if
 needle is not part of haystack.

 Solution:

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
	char *strStr(char *haystack, char *needle) {
		int len1 = strlen(haystack);
		int len2 = strlen(needle);
		bool flag;

		for (int i = 0; i < len1 - len2 + 1; i++) {
			flag = true;
			for (int j = 0; j < len2; j++) {
				if (haystack[i + j] != needle[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return haystack + i;
			}
		}
		return NULL;
	}
};
