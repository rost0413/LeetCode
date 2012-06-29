/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       June 28, 2012
 Problem:    Gray Code
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 The gray code is a binary numeral system where two successive values differ in
 only one bit.

 Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2

 Solution:
 n = 3
 000 - 0
 001 - 1
 011 - 3
 010 - 2
 110 - 6
 111 - 7
 101 - 5
 100 - 4

 If we try to find the regular of the gray code, we will find that the first
 digit (from right to left) has certain pattern '0110', repeat every four
 string. And the second digit has pattern '00111100', repeat every eight string.
 The third digit has pattern '0000111111110000'...

 After wiki, gray code is very famous math notion. And the generation function
 actually only takes 1 lines of code:
 	unsigned int binaryToGray(unsigned int num)
	{
        return (num >> 1) ^ num;
	}
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
	vector<int> result;

	/*
	 * n is the string sequence number, it determines which code to
	 * use (0 or 1); m is the digit sequence number, it determines
	 * which pattern to use ('0110', '00111100', ...)
	 */
	void genDigit(int& code, int n, int m) {
		int len = 1 << (m + 2);
		n &= ((1 << (m + 2)) - 1);
		if (n >= (len >> 2) && n < len - (len >> 2)) {
			code |= 1 << m;
		}
		else {
			code &= ~(1 << m);
		}
	}

	vector<int> grayCode(int n) {
		int round = 1 << n;
		int code;

		result.clear();
		for (int i = 0; i < round; i++) {
			code = 0;
			for (int j = 0; j < n; j++) {
				genDigit(code, i, j);
			}
			result.push_back(code);
		}
		return result;
	}
};

