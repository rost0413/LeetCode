/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 26, 2012
Problem:    Combination Sum II
Difficulty: Easy
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given a collection of candidate numbers (C) and a target number (T), find all unique
 combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … ,ak) must be in non-descending order.
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

Solution:
This is the original knapsack problem. The initialization of the sum matrix
is as following:
   0 1 2 3 4 5 6 7 8
0  1 0 0 0 0 0 0 0 0
1  1
1  1
2  1
5  1
6  1
7  1
10 1

The difference from previous Combination Sum problem is the sum can be computed
from left-top and top.
Path: 1 means computed from top, 2 means from left-top, 3 means both, -1 means
not exist.

Is there a better ways to construct the path?
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
    bool **sum;
    int **path;
    set<vector<int> > result;

    void searchPath(int i, int j, vector<int> p, vector<int> &num) {
        if (j == 0 || i == 0) {
            sort(p.begin(), p.end());
            result.insert(p);
            return;
        }

        if (path[i][j] == 1) {
            //p.push_back(num[i - 2]);
            searchPath(i - 1, j, p, num);
        }
        else if (path[i][j] == 2) {
            p.push_back(num[i - 1]);
            searchPath(i - 1, j - num[i - 1], p, num);
        }
        else if (path[i][j] == 3) {
            searchPath(i - 1, j, p, num);

            p.push_back(num[i - 1]);
            searchPath(i - 1, j - num[i - 1], p, num);
        }
        return;
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        result.clear();
        sum = new bool* [num.size() + 1];
        path = new int* [num.size() + 1];
        for (size_t i = 0; i < num.size() + 1; i++) {
            sum[i] = new bool[target + 1];
            path[i] = new int[target + 1];
        }

        // initialize
        for (int i = 0; i < num.size() + 1; i++) {
            sum[i][0] = true;
            path[i][0] = -1;
        }
        for (int i = 1; i < target + 1; i++) {
            sum[0][i] = false;
            path[0][i] = -1;
        }

        // construct the sum matrix and path matrix.
        for (int i = 1; i < num.size() + 1; i++) {
            for (int j = 1; j < target + 1; j++) {
                if (j - num[i - 1] < 0) {
                    if (sum[i - 1][j]) {
                        sum[i][j] = true;
                        path[i][j] = 1;
                    }
                    else {
                        sum[i][j] = false;
                        path[i][j] = -1;
                    }
                }
                else {
                    if (sum[i - 1][j - num[i - 1]] && sum[i - 1][j]) {
                        sum[i][j] = true;
                        path[i][j] = 3;
                    }
                    else if (sum[i - 1][j - num[i - 1]]) {
                        sum[i][j] = true;
                        path[i][j] = 2;
                    }
                    else if (sum[i - 1][j]) {
                        sum[i][j] = true;
                        path[i][j] = 1;
                    }
                    else {
                        sum[i][j] = false;
                        path[i][j] = -1;
                    }
                }
            }
        }

         // construct the path
        for (size_t i = 1; i < num.size() + 1; i++) {
            if (path[i][target] != -1) {
                vector<int> p;
                searchPath(i, target, p, num);
            }
        }

        // delete
        for (size_t i = 0; i < num.size() + 1; i++) {
            delete[] sum[i];
            delete[] path[i];
        }
        delete[] sum;
        delete[] path;

        vector<vector<int> > vec;
        vec.resize(result.size());
        copy(result.begin(), result.end(), vec.begin());
        return vec;
    }
};




