/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jun 29, 2012
 Problem:	 Insert Interval
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a set of non-overlapping intervals, insert a new interval into the intervals
 (merge if necessary).

 You may assume that the intervals were initially sorted according to their start
 times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Solution:
 overlap situations:
 1) a: ----------
    b:     -----------
 2) a: ---------------
    b:     -----
 3) a:      -------
 	b: -------
 4) a:    ----
 	b: -----------
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

class Solution {
public:
	bool overlap(Interval a, Interval b) {
		if ((a.end >= b.start && a.start <= b.start)
			|| (a.start <= b.end && a.end >= b.end)
			|| (a.start <= b.start && a.end >= b.end)
			|| (b.start <= a.start && b.end >= a.end))
			return true;
		return false;
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		bool flag;
		int start, end;

		result.clear();
		flag = true;

		for (unsigned i = 0; i < intervals.size(); i++) {
			if (overlap(intervals[i], newInterval)){
				flag = false;
				start = min(intervals[i].start, newInterval.start);
				while (overlap(intervals[i], newInterval) && i < intervals.size()){
					end = max(intervals[i].end, newInterval.end);
					i++;
				}
				i--;
				result.push_back(Interval(start, end));
			}
			else {
				if (flag && intervals[i].start > newInterval.start) {
					flag = false;
					result.push_back(newInterval);
				}
				result.push_back(intervals[i]);
			}
		}
		if (flag) {
			result.push_back(newInterval);
		}

		return result;
	}
};
