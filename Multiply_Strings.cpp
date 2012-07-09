/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 8, 2012
 Problem:    Multiply Strings
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given two numbers represented as strings, return multiplication of the numbers
 as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
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
	string reverse(string str) {
		string r;
		for (int i = str.length() - 1; i >= 0; i--) {
			r += str[i];
		}
		return r;
	}
	string add(string num1, string num2) {
		stringstream result;
		unsigned carry, i;

		for (i = 0, carry = 0; i < num1.length() && i < num2.length(); i++) {
			int sum = num1[i] - '0' + num2[i] - '0' + carry;
			result << sum % 10;
			carry = sum / 10;
		}
		num1 = (i < num1.length() ? num1 : num2);
		for (; i < num1.length(); i++) {
			int sum = num1[i] - '0' + carry;
			result << sum % 10;
			carry = sum / 10;
		}
		if (carry) {
			result << carry;
		}
		return result.str();
	}

	string multiply(string num1, string num2) {
		string result;
		string cum[10];

		num1 = reverse(num1);
		num2 = reverse(num2);
		cum[0] = "0";
		for (unsigned i = 1; i <= 9; i++) {
			cum[i] = add(cum[i - 1], num1);
		}
		for (unsigned i = 0; i < num2.length(); i++) {
			string factor;
			for (unsigned j = 0; j < i; j++) {
				factor += "0";
			}
			if (cum[(int) (num2[i] - '0')].compare("0") == 0) {
				factor = "0";
			} else {
				factor += cum[(int) (num2[i] - '0')];
			}
			result = add(result, factor);
		}
		return reverse(result);
	}
};
