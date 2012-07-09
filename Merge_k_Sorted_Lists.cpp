/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 6, 2012
 Problem:    Merge k Sorted Lists
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Merge k sorted linked lists and return it as one sorted list. Analyze and
 describe its complexity.

 Solution:
 Use min heap, the time complexity is O(n*lgk), n is the number of elelments
 of all lists.
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

struct Compare {
	bool operator ()(const ListNode* a, const ListNode* b) {
		return a->val > b->val;
	}
};
class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
		ListNode *head = NULL;
		ListNode *tail = NULL;

		for (unsigned i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				min_heap.push(lists[i]);
			}
		}

		while (!min_heap.empty()) {
			ListNode *node = min_heap.top();
			min_heap.pop();
			if (head == NULL) {
				head = node;
				tail = node;
			} else {
				tail->next = node;
				tail = node;
			}
			node = node->next;
			if (node != NULL) {
				min_heap.push(node);
			}
		}

		return head;
	}
};
