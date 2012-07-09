/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 27, 2012
Problem:    Count and Say
Difficulty: easy
Source:     http://www.leetcode.com/onlinejudge
Notes:
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Solution:
Easy simulation.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> result;
    Solution () {
        result.push_back("1");
    }
    string countAndSay(int n) {
        while (result.size() < n) {
            string str = result.back();
            stringstream next;
            for (int i = 0; i < str.length(); i++) {
                int count = 1;
                while (str[i] == str[i + 1] && i < str.length()) {
                    count++;
                    i++;
                }
                next << count << str[i];
            }
            result.push_back(next.str());
        }

        return result[n - 1];
    }
};





