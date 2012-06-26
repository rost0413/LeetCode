/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 26, 2012
Problem:    faster version of Combination Sum
Difficulty: medium
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
Noticed that in the construction of sum matrix and path matrix, every row is
deducted only from up row (sum[x][y] is deducted from either sum[x-1][y] or
sum[x-1][y-num]). Thus it is possible to reduce the 2-dimension array to
1-dimension array. And we can save the path in the process of construction and
dont have to reconstruct path afterwards.

The only difference of faster versions of combiation sum and combination sum II is
the direction second loop.

Although this version is way faster than the original code, it is still much slower
than the naive code below (commented). The path construction part is still critical.
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
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        bool sum[target + 1];
        set<vector<int> > path[target + 1];

        // initialize
        for (int i = 0; i < target + 1; i++) {
            path[i].clear();
            sum[i] = false;
        }
        sum[0] = true;
        sort(num.begin(), num.end());

        for (size_t i = 0; i< num.size(); i++) {
            for (int j = num[i]; j <= target; j++) {
                if (sum[j - num[i]]) {
                    sum[j] = true;
                    if (path[j - num[i]].empty()) {
                        vector<int> vec;
                        vec.push_back(num[i]);
                        path[j].insert(vec);
                    }
                    else {
                        set<vector<int> >::iterator it;
                        for (it = path[j - num[i]].begin(); it != path[j - num[i]].end(); it++) {
                            vector<int> vec = *it;
                            vec.push_back(num[i]);
                            path[j].insert(vec);
                        }
                    }
                }
            }
        }

        vector<vector<int> > vec;
        vec.resize(path[target].size());
        copy(path[target].begin(), path[target].end(), vec.begin());
        return vec;

    }
};



//class Solution {
//public:
//        vector<vector<int> > results;
//
//        void combinationSum(int sum, int target, const vector<int> &cand, int index, vector<int> &queue) {
//                if(sum == target) {
//                        results.push_back(queue);
//                        return;
//                }
//
//                for(int i = index; i<cand.size(); i++) {
//                        if(sum + cand[i] <= target) {
//                                queue.push_back(cand[i]);
//
//                                combinationSum(sum + cand[i], target, cand, i, queue);
//
//                                queue.pop_back();
//                        }
//                        else
//                                break;
//                }
//
//        }
//
//        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
//                vector<int> cand = candidates;
//                vector<int> queue;
//
//                results.clear();
//                sort(cand.begin(), cand.end());
//                combinationSum(0, target, cand, 0, queue);
//
//                return results;
//        }
//};





