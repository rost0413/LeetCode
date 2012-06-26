/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 26, 2012
Problem:    Combination Sum
Difficulty: Medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given a set of candidate numbers (C) and a target number (T), find all unique
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … ,ak) must be in non-descending order.
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

Solution:
It's variant of classic knapsack problem. The initialization of sum matrix is following:
  0 1 2 3 4 5 6 7
0 1 0 0 0 0 0 0 0
2 1
3 1
6 1
7 1

path: 1 means from top, 2 means from left, 3 means from both top and left, -1
means path not exists;

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

    void searchPath(int i, int j, vector<int> p, vector<int> &candidates) {
        if (j == 0) {
            sort(p.begin(), p.end());
            result.insert(p);
            return;
        }

        if (path[i][j] == 1) {
            //p.push_back(candidates[i - 2]);
            searchPath(i - 1, j, p, candidates);
        }
        else if (path[i][j] == 2) {
            p.push_back(candidates[i - 1]);
            searchPath(i, j - candidates[i - 1], p, candidates);
        }
        else if (path[i][j] == 3) {
            searchPath(i - 1, j, p, candidates);

            p.push_back(candidates[i - 1]);
            searchPath(i, j - candidates[i - 1], p, candidates);
        }
        return;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        result.clear();
        sum = new bool* [candidates.size() + 1];
        path = new int* [candidates.size() + 1];
        for (size_t i = 0; i < candidates.size() + 1; i++) {
            sum[i] = new bool[target + 1];
            path[i] = new int[target + 1];
        }

        // initialize
        for (size_t i = 0; i < candidates.size() + 1; i++) {
            sum[i][0] =  true;
            path[i][0] = 0;
        }
        for (int i = 1; i < target + 1; i++) {
            sum[0][i] = false;
            path[0][i] = -1;
        }

        // dynamic programming, construct the sum matrix and path matrix.
        for (size_t i = 1; i < candidates.size() + 1; i++) {
            for (int j = 1; j< target + 1; j++) {
                if (j - candidates[i - 1] < 0) {
                    sum[i][j] = sum[i - 1][j];
                    if (sum[i - 1][j])
                        path[i][j] = 1;
                    else
                        path[i][j] = -1;
                }
                else {
                    if (sum[i - 1][j] && sum[i][j - candidates[i - 1]]) {
                        sum[i][j] = true;
                        path[i][j] = 3;
                    }
                    else if (sum[i][j - candidates[i - 1]]) {
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

        // construct the path from path matrix.
        for (size_t i = 1; i < candidates.size() + 1; i++) {
            if (path[i][target] != -1) {
                vector<int> p;
                searchPath(i, target, p, candidates);
            }
        }

        // delete
        for (size_t i = 0; i < candidates.size() + 1; i++) {
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



