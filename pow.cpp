/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 11, 2012
 Problem:    pow(x, n)
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Implement pow(x, n).
 Solution:
 Be careful about the boundry test and write neat expontential step
 algorithm to avoid TLE.
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
	double pow(double x, int n) {
		double result = 1.0;
		double step = x;
		for (int i = abs(n); i > 0; i /= 2) {
			if (i & 1) {
				result *= step;
			}
			step *= step;
		}
		result = (n < 0 ? 1 / result : result);
		return result;
	}
};
