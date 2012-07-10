/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 8, 2012
 Problem:    Next Permutation
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Implement next permutation, which rearranges numbers into the lexicographically
 next greater permutation of numbers.

 If such arrangement is not possible, it must rearrange it as the lowest possible
 order (ie, sorted in ascending order).

 The replacement must be in-place, do not allocate extra memory.

 Here are some examples. Inputs are in the left-hand column and its corresponding
 outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 Solution:
 http://en.wikipedia.org/wiki/Permutation
 The following algorithm generates the next permutation lexicographically after
 a given permutation. It changes the given permutation in-place.

 Find the largest index k such that a[k] < a[k + 1]. If no such index exists,
 the permutation is the last permutation.
 Find the largest index l such that a[k] < a[l]. Since k + 1 is such an index,
 l is well defined and satisfies k < l.
 Swap a[k] with a[l].
 Reverse the sequence from a[k + 1] up to and including the final element a[n].
 After step 1, one knows that all of the elements strictly after position k form
 a weakly decreasing sequence, so no permutation of these elements will make it
 advance in lexicographic order; to advance one must increase a[k]. Step 2 finds
 the smallest value a[l] to replace a[k] by, and swapping them in step 3 leaves
 the sequence after position k in weakly decreasing order. Reversing this
 sequence in step 4 then produces its lexicographically minimal permutation, and
 the lexicographic successor of the initial state for the whole sequence.
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
	void reverse(vector<int> &num, int s, int t) {
		for (int i = s; i < (t + s + 1) / 2; i++) {
			swap(num[i], num[t + s - i]);
		}
	}
	void nextPermutation(vector<int> &num) {
		int k = -1;
		int l;
		for (int i = num.size() - 1; i >= 1; i--) {
			if (num[i] > num[i - 1]) {
				k = i - 1;
				break;
			}
		}
		if (k == -1) {
			reverse(num, 0, num.size() - 1);
			return;
		}
		for (int i = num.size() - 1; i > k; i--) {
			if (num[i] > num[k]) {
				l = i;
				break;
			}
		}
		swap(num[k], num[l]);
		reverse(num, k + 1, num.size() - 1);
	}
};
