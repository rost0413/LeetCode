/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 21, 2012
Problem:    4 Sum
Difficulty: medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum
of target.
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Solution:
The idea is different with 3 Sum problem and 3 Sum Closest problem. Frist compute the sum
of every two elements and sort them, this takes O(n^2) + O(n*lgn). Then for every element
in the sorted array, binary search for the corresponding element that give the sum equals
target, this takes O(n^2 * lgn). Thus the total time complexity is O(n^2*lgn)

A good STL sort comparison function guide: http://www.codeproject.com/Articles/38381/STL-Sort-Comparison-Function
This code doesn't pass the large judege of Leetcode, but when I test the wrong test cases
on my own machine, the code runs the correct output. I don't why.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Triple {
public:
    int sum;
    int val1;
    int val2;
    Triple (int x) {
        this->sum = x;
    }
    Triple (int x, int y, int z) {
        this->sum = x;
        this->val1 = y;
        this->val2 = z;
    }
    bool operator < (const Triple& rhs) const {
        return this->sum < rhs.sum;
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<Triple> sum2;
        vector<Triple>::iterator it;
        set<vector<int> > solset;
        vector<int> quar(4);
        vector<vector<int> > sol;

        if (num.size() < 4) {
            return sol;
        }

        for (int i = 0; i < num.size() - 1; i++) {
            for (int j = i + 1; j < num.size(); j++) {
                sum2.push_back(Triple(num[i] + num[j], i, j));
            }
        }

        sort(sum2.begin(), sum2.end());
        for (int i = 0; i < sum2.size(); i++) {
            it = lower_bound(sum2.begin(), sum2.end(), Triple(target - sum2[i].sum));
            Triple t1 = sum2[i];
            Triple t2 = *it;
            if (t1.val1 != t2.val1 && t1.val1 != t2.val2
                && t1.val2 != t2.val1 && t1.val2 != t2.val2
                && t1.sum + t2.sum == target) {
                quar[0] = num[t1.val1];
                quar[1] = num[t1.val2];
                quar[2] = num[t2.val1];
                quar[3] = num[t2.val2];
                sort(quar.begin(), quar.end());
                solset.insert(quar);
            }
        }

        sol.resize(solset.size());
        copy(solset.begin(), solset.end(), sol.begin());
        return sol;
    }
};


