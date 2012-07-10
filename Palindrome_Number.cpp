/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 9, 2012
 Problem:    Palindrome Number
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Determine whether an integer is a palindrome. Do this without extra space.
 Solution:
 Some hints:
 Could negative integers be palindromes? (ie, -1)

 If you are thinking of converting the integer to string, note the restriction
 of using extra space.

 You could also try reversing an integer. However, if you have solved the problem
 "Reverse Integer", you know that the reversed integer might overflow. How would
 you handle such case?

 There is a more generic way of solving this problem.

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
	bool isPalindrome(int x) {
		int len = 0;
		if (x < 0) {
			return false;
		}
		while ((int) (x / pow(10.0, len))) {
			len++;
		}
		for (int i = 0; i < len / 2; i++) {
			if ((int) (x / pow(10.0, i)) % 10
					!= (int) (x / pow(10.0, len - i - 1)) % 10) {
				return false;
			}
		}
		return true;
	}
};
