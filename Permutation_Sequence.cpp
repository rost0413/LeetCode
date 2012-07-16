/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 10, 2012
 Problem:    Permutation Sequence
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 The set [1,2,3,…,n] contains a total of n! unique permutations.

 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.

 Note: Given n will be between 1 and 9 inclusive.
 Solution:
 For set [1,2,3,...,n], there are a total of n! unique permutations.
 Then we know there are n!/n=(n-1)! permutations start with 1, n!/n=(n-1)!
 permutations start with 2, etc.
 To get the kth permutation, We satrt by locating the digit from left
 to right.
 For n = 9, there are 362 880 unique permutations.
 1 - 40320 starts with 1
 40321 - 80640 starts with 2
 80641 - 120960 starts with 3
 ...

 */
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;

class Solution {
public:
	int factorial(int n) {
		if (n == 1 || n == 0) {
			return 1;
		}
		return n * factorial(n - 1);
	}
	string getPermutation(int n, int k) {
		list<int> num;
		string result;

		for (int i = 1; i <= n; i++) {
			num.push_back(i);
		}

		for (int i = 0; i < n; i++) {
			int f = factorial(n - i - 1);
			int j = 0;
			list<int>::iterator it = num.begin();
			while (j * f < k) {
				j++;
				it++;
			}
			it--;
			j--;
			k -= j * f;
			result.push_back(*it + '0');
			num.erase(it);
		}
		return result;
	}
};
