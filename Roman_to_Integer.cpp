/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 15, 2012
 Problem:    Roman to Integer
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a roman numeral, convert it to an integer.

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
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> symbol;
		int sum, result = 0;

		symbol.insert(pair<char, int>('I', 1));
		symbol.insert(pair<char, int>('V', 5));
		symbol.insert(pair<char, int>('X', 10));
		symbol.insert(pair<char, int>('L', 50));
		symbol.insert(pair<char, int>('C', 100));
		symbol.insert(pair<char, int>('D', 500));
		symbol.insert(pair<char, int>('M', 1000));

		for (unsigned i = 0; i < s.length(); i++) {
			if (i == 0) {
				sum = symbol[s[i]];
			} else if (symbol[s[i - 1]] > symbol[s[i]]) {
				result += sum;
				sum = symbol[s[i]];
			} else if (symbol[s[i - 1]] == symbol[s[i]]) {
				sum += symbol[s[i]];
			} else {
				result += symbol[s[i]] - sum;
				sum = 0;
			}
		}
		result += sum;
		return result;
	}
};
