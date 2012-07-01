/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jun 29, 2012
 Problem:    Integer to Roman
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given an integer, convert it to a roman numeral.

 Input is guaranteed to be within the range from 1 to 3999.

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
	string intToRoman(int num) {
		string roman;
		string digits[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

		int thousands = num / 1000;
		for (int i = 0; i < thousands; i++) {
			roman += 'M';
		}
		num = num - thousands * 1000;
		roman += hundreds[num / 100];
		num = num - num / 100 * 100;
		roman += tens[num / 10];
		num = num - num / 10 * 10;
		roman += digits[num];

		return roman;
	}
};
