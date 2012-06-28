/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 28, 2012
Problem:    First Missing Positive
Difficulty: easy
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Solution:
Two traverses.
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
    int firstMissingPositive(int A[], int n) {
        bool arr[n + 2];
        int result = 1;

        for (int i = 1; i < n + 2; i++) {
            arr[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (A[i] > 0 && A[i] < n + 1) {
                arr[A[i]] = true;
            }
        }

        for (int i = 1; i < n + 2; i++) {
            if (!arr[i]) {
                result = i;
                break;
            }
        }
        return result;
    }
};



