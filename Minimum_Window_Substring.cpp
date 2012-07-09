/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 7, 2012
 Problem:    Minimum Window Substring
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a string S and a string T, find the minimum window in S which will contain
 all the characters in T in complexity O(n).

 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".

 Note:
 If there is no such window in S that covers all characters in T, return the emtpy
 string "".

 If there are multiple such windows, you are guaranteed that there will always be
 only one unique minimum window in S.

 Solution:
 Idea comes from
 http://stackoverflow.com/questions/2459653/how-to-find-smallest-substring-which-contains-all-characters-from-a-given-string
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
	string minWindow(string S, string T) {
		int count[128] = { 0 };
		int map[128] = { 0 };
		int rstart, rend, len;

		for (unsigned i = 0; i < T.length(); i++) {
			count[(int) T[i]]++;
		}

		rstart = -1;
		len = 0;
		for (unsigned end = 0, start = 0; end < S.length(); end++) {
			map[(int) S[end]]++;
			len = (map[(int) S[end]] <= count[(int) S[end]] ? len + 1 : len);
			while (len == T.length()) {
				if (end - start < rend - rstart || rstart == -1) {
					rstart = start;
					rend = end;
				}
				map[(int) S[start]]--;
				len = (map[(int) S[start]] < count[(int) S[start]] ?
						len - 1 : len);
				start++;
			}
		}

		return (rstart == -1 ? "" : S.substr(rstart, rend - rstart + 1));
	}
};
