/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 1, 2012
 Problem:    Letter Combinations of a Phone Number
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a digit string, return all possible letter combinations that the number
 could represent.

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
	string arr[10];
	vector<string> result;
	void recursion(string digits, unsigned n, string str) {
		if (n >= digits.length()) {
			result.push_back(str);
			return;
		}
		for (unsigned i = 0; i < arr[digits[n] - '0'].length(); i++) {
			recursion(digits, n + 1, str + arr[digits[n] - '0'][i]);
		}
	}

    vector<string> letterCombinations(string digits) {
    	result.clear();
    	for (int i= 0; i< 10; i++) {
    		arr[i].clear();
    	}

    	arr[0] = " ";
    	arr[1] = "";
    	arr[2] = "abc";
    	arr[3] = "def";
    	arr[4] = "ghi";
    	arr[5] = "jkl";
    	arr[6] = "mno";
    	arr[7] = "pqrs";
    	arr[8] = "tuv";
    	arr[9] = "wxyz";

    	recursion(digits, 0, "");
    	return result;
    }
};
