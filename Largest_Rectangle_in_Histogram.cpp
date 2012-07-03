/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 1, 2012
 Problem:    Largest Rectangle in Histogram
 Difficulty: hard
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given n non-negative integers representing the histogram's bar height where
 the width of each bar is 1, find the area of largest rectangle in the histogram.

 Solution:
 This problem is different with Container with most water. The volume here is
 determined by the shorest line between the two lines instead of the shorter
 one of the two lines.

 We traverse from left to right, regard each line as the shortest line (center line)
 and try to extend the width as far as possible. We try to reach the first line
 that is shorter than our center line when extend its left, and this line determines
 the left width of center line. We can find the right width with same method. With
 left and right width we can easily get the answer by another traverse.

 But how to reach the correct line? This is the most difficult problem. The solution
 is borrowing a stack. When we do extension on both directions, pop and push by
 following rules:
 compare with stack top,
 1. if it is empty, push index of current line;
 2. if current line is longer, push index of current line.
 3. if current line is shorter, pop until the top is shorter than or equal to current
 line or the stack is empty, then push index of current line.
 4. if current line is equal with stack top, just ignore.
 */
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		stack<int> s, t;
		int width[height.size()];
		int result;

		for (unsigned i = 0; i < height.size(); i++) {
			while (!s.empty() && height[i] <= height[s.top()]) {
				s.pop();
			}
			int top = (s.empty() ? -1 : s.top());
			width[i] = i - top - 1;
			s.push(i);
		}

		for (int i = height.size() - 1; i >= 0; i--) {
			while (!t.empty() && height[i] <= height[t.top()]) {
				t.pop();
			}
			int top = t.empty() ? height.size() : t.top();
			width[i] += top - i - 1;
			t.push(i);
		}

		result = 0;
		for (unsigned i = 0; i < height.size(); i++) {
			int area = height[i] * (width[i] + 1);
			result = max(result, area);
		}

		return result;
	}
};
