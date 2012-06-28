/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 28, 2012
Problem:    Gray Code
Difficulty: easyt
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

    void recursion(int start, int num, int n) {
        if (start == n) {
            result.push_back(num);
        }
        for (int i = start; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                recursion(i + 1, num ^ (j << (n - i - 1)), n);
            }
        }
    }

    vector<int> grayCode(int n) {
        result.clear();
        recursion(0, 0, n);

        return result;
    }
};



