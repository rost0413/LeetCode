/*
Author:     Weixian Zhou, ideazwx@gmail.com
Date:       June 28, 2012
Problem:    Edit Distance
Difficulty: medium
Source:     http://www.leetcode.com/onlinejudge
Notes:
Given two words word1 and word2, find the minimum number of steps required to convert
word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Solution:
This is a dynamic programming problem. The problem is similar to longest common
substring problem. Here we define f[n, m] as the minimum edit distance of string
a[0..n] and b[0..m]. Then
f[n, m] = f[n-1,m-1], if a[n] == b[m]
        = min{f[n-1,m]+1, f[n,m-1]+1, f[n-1,m-1]+1}, if a[n] != b[m].
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
    int minimal(int a, int b, int c) {
        int min = a;
        if (b < min) min = b;
        if (c < min) min = c;
        return min;
    }
    int minDistance(string word1, string word2) {
       int ed[word1.length() + 1][word2.length() + 1];

        // initialize
       for (int i = 0; i < word1.length() + 1; i++) {
            ed[i][0] = i;
       }
       for (int i = 0; i < word2.length() + 1; i++) {
            ed[0][i] = i;
       }

        // DP
       for (int i = 1; i < word1.length() + 1; i++) {
            for (int j = 1; j < word2.length() + 1; j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        ed[i][j] = ed[i -1][j - 1];
                    }
                    else {
                        ed[i][j] = minimal(ed[i - 1][j] + 1,
                                           ed[i][j - 1] + 1,
                                           ed[i - 1][j - 1] + 1);
                    }
            }
       }

       return ed[word1.length()][word2.length()];
    }
};

