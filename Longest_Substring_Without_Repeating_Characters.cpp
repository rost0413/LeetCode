/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 3, 2012
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string, find the length of the longest substring without repeating
 characters. For example, the longest substring without repeating letters for
 "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
 is "b", with the length of 1.

 Solution:
 Implement a queue.
 */
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		queue<int> *que = new queue<int>;
		bool map[26];
		unsigned maxlen = 0;

		for (int i = 0; i < 26; i++) {
			map[i] = 0;
		}
		for (unsigned i = 0; i < s.length(); i++) {
			if (map[s[i] - 'a']) {
				while (que->front() != s[i] - 'a') {
					map[que->front()] = false;
					que->pop();
				}
				que->pop();
			} else {
				map[s[i] - 'a'] = true;
			}
			que->push(s[i] - 'a');
			maxlen = (que->size() > maxlen ? que->size() : maxlen);
		}

		delete que;
		return maxlen;
	}
};
