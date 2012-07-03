/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 1, 2012
 Problem:    Length of Last Word
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string s consists of upper/lower-case alphabets and empty space
 characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space
 characters only.

 For example,
 Given s = "Hello World",
 return 5.

 Solution:
 simple.
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
    int lengthOfLastWord(const char *s) {
    	if (s == NULL) {
    		return 0;
    	}

    	int i = strlen(s) - 1;
    	while (i >= 0 && s[i] == ' ') {
    		i--;
    	}

    	int len = 0;
    	while (i >= 0 && s[i] != ' ') {
    		len++;
    		i--;
    	}

    	return len;
    }
};
