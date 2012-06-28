/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 27, 2012
Problem:    Decode ways
Difficulty: medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
A message containing letters from A-Z is being encoded to numbers using
the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of
ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Solution:
I think the problem has a dynamic programming solution. Assume f(n) is the
number of ways decoding left n characters of string s. Then we can get
f[n] = f[n-1] + f[n-2], if both s[n-1,n] and s[n] can be decoded;
     = f[n-1], if s[n-1,n] can't be decoded, s[n] can be decoded;
     = f[n-2], if s[n-1,n] can be decode,, but s[n] can't be decoded;
     = 0, if neither s[n-1,n] and s[n] can be decoded.
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
    bool canDecode(string num) {
        if (num.length() == 1) {
            if (num[0] == '0')
                return false;
            return true;
        }
        else {
            if (num[0] != '1' && num[0] != '2')
                return false;
            int value;
            stringstream(num) >> value;
            if (value > 26)
                return false;
            return true;
        }
    }

    int numDecodings(string s) {
        int f[s.length() + 1];
        int value;

        if (s.empty()) {
            return 0;
        }

        f[0] = 1;
        if (canDecode(s.substr(0, 1))) {
            f[1] = 1;
        }
        else {
            f[1] = 0;
        }

        for (int i = 1; i < s.length(); i++) {
            bool a = canDecode(s.substr(i - 1, 2));
            bool b = canDecode(s.substr(i, 1));
            if (a && b) {
                f[i + 1] = f[i] + f[i - 1];
            }
            else if (!a && b) {
                f[i + 1] = f[i];
            }
            else if (a && !b) {
                f[i + 1] = f[i - 1];
            }
            else {
                f[i + 1] = 0;
            }
        }

        return f[s.length()];
    }
};
