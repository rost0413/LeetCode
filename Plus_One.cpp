/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 11, 2012
 Problem:    Plus One
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a number represented as an array of digits, plus one to the number.
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
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result;
		int carry = 1;

		result.clear();
		for (int i = digits.size() - 1; i >= 0; i--) {
			int sum = digits[i] + carry;
			digits[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry) {
			result.push_back(1);
		}
		result.insert(result.end(), digits.begin(), digits.end());

		return result;
	}
};
