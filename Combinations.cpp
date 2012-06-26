/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 26, 2012
Problem:    Combinations
Difficulty: Easy
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Solution:
Pure recursion.
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
    vector<vector<int> > result;
    int max;
    int num;

    void recursion(int index, vector<int> q) {
        if (q.size() >= num) {
            result.push_back(q);
            return;
        }
        for (int i = index; i <= max; i++) {
            q.push_back(i);
            recursion(i + 1, q);
            q.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        max = n;
        num = k;
        result.clear();

        vector<int> q;
        recursion(1, q);

        return result;
    }
};




