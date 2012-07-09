/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 6, 2012
 Problem:    Merge Intervals
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a collection of intervals, merge all overlapping intervals.

 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].

 Solution:
 This problem can be soloved in two ways. First, sort the entire vector in the
 ascending order of the start point, then merge the interval in a traverse.
 This takes O(nlgn) time.
 Another elegant method is using interval tree. This method allows fast retrieval,
 but the contruction time (O(nlgn)) is no better than the first method. Thus
 I adopt the first method.
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

struct Interval {
	int start;
	int end;
	Interval() :
			start(0), end(0) {
	}
	Interval(int s, int e) :
			start(s), end(e) {
	}
};

struct Compare {
	bool operator ()(const Interval& a, const Interval& b) {
		return a.start < b.start;
	}
} compare;

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), compare);
		int s, t;

		result.clear();
		if (intervals.size() == 0) {
			return result;
		}
		s = intervals[0].start;
		t = intervals[0].end;
		for (unsigned i = 0; i < intervals.size(); i++) {
			if (intervals[i].start <= t) {
				t = max(t, intervals[i].end);
				continue;
			}
			result.push_back(Interval(s, t));
			s = intervals[i].start;
			t = intervals[i].end;
		}
		result.push_back(Interval(s, t));

		return result;
	}
};
