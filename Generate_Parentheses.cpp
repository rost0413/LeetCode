/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 28, 2012
Problem:    Generate Parentheses
Difficulty: easy
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Solution:
This is similar to stack operations. Left parentheses is pushing to stack and
right parenthese is popping from stack. The goal is to make sure there are
exactly no element in the stack.
Here I use addition operation to simulate the stack operation. +1 means pushing
and -1 means popping, at the end the sum has to be zero. And this will be a
well-formed parentheses. For example, if the input n = 3. Then the number of +1
operation as well as the number of -1 operation is 3. If n1==0 && n2==0 and
sum==0 in the recursion, it is a well-formed parentheses. Anytime the sum has to
be greater than zero. Either n1 or n2 minus 1 in the process of recursion.
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
    vector<string> result;

    /*
     * parameter: n1 is the available number of +1 operation,
     * n2 is the available number of -1 operation, sum is the result of operation
     * and has to be greater than zero always, string s is the sequence of parentheses.
     */
    void recursion(int n1, int n2, int sum, string s) {
        if (n1 == 0 && n2 == 0 && sum == 0) {
            result.push_back(s);
            return;
        }
        if (n1 < 0 || n2 < 0 || sum < 0) {
            return;
        }
        if (sum > 0) {
            recursion(n1, n2 - 1, sum - 1, s + ")");
        }
        recursion(n1 - 1, n2, sum + 1, s + "(");
    }

    vector<string> generateParenthesis(int n) {
        result.clear();
        recursion(n, n, 0, "");

        return result;
    }
};



