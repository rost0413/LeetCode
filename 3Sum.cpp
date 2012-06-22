/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 18, 2012
Problem:    3 Sum
Difficulty: medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
The solution set must not contain duplicate triplets.

Solution:
This problem is the extension of the problem below:
Given a set S of n integers, find all pairs of integers of a and b in S such that a + b = k?

The above problem can be solved in O(n) time, assuming that the set S is already sorted. By
using two index first and last, each pointing to the first and last element, we look at the
element pointed by first, which we call A. We know that we need to find B = k – A, the
complement of A. If the element pointed by last is less than B, we know that the choice is
to increment pointer first by one step. Similarly, if the element pointed by last is greater
than B, we decrement pointer last by one step. We are progressively refining the sum step by
step. Since each step we move a pointer one step, there are at most n steps, which gives the
complexity of O(n).

By incorporating the solution above, we can solve the 3sum problem in O(n^2) time, which is
a straight forward extension.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int> > solset;
        vector<int> triple(3);
        int i, j, k;
        int n = num.size();
        int sum;

        sort(num.begin(), num.end());

        for (i = 0; i < n; i++) {
            if (i == 0) {
                sum = -num[i];
            }
            else {
                if (sum == -num[i]) {
                    continue;
                }
                sum = -num[i];
            }

            for (j = 0, k = n - 1; j < k; ) {
                if (num[j] + num[k] < sum || j == i) {
                    j++;
                }
                else if (num[j] + num[k] > sum || k == i) {
                    k--;
                }
                else {
                    triple[0] = -sum;
                    triple[1] = num[j];
                    triple[2] = num[k];
                    sort(triple.begin(), triple.end());
                    solset.insert(triple);
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int> > sol(solset.begin(), solset.end());
        return sol;
    }
};
