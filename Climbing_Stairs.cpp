/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 25, 2012
Problem:    Climbing Stairs
Difficulty: Medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Solution:
Suppose there are f(n) ways to reach the n-step top, and the last step is either 1 or 2. Thus
we can get f(n) = f(n-1) + f(n-2). This is exactly the Fibonacci sequence. Thus we can compute
the nth fibonacci number by recursive calls and memorization.
The time complexity of Fibonacci sequence is about O(1.618^n), (1.616 is the gold ratio).
Here are good discussions about this.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
    int memo[100];
    int fib(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        memo[n - 1] = (memo[n - 1] == -1 ? fib(n - 1) : memo[n - 1]);
        memo[n - 2] = (memo[n - 2] == -1 ? fib(n - 2) : memo[n - 2]);
        return memo[n - 1] + memo[n - 2];
    }

    int climbStairs(int n) {
        memset(memo, -1, sizeof(memo));

        return fib(n);
    }
};


