/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 15, 2012
 Problem:	 Reverse Linked List II
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 Solution:
 Open a new list and traverse the original list, when encounter a node not
 in the reverse segment, insert after the tail; else insert before the tail.
 This method is O(n).
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int count = 1;
		ListNode *rhead, *cur, *rtail, *newhead;

		/* an empty head to make the operation easier */
		rhead = new ListNode(1);
		newhead = rhead;
		rhead->next = head;
		while (count < m) {
			count++;
			rhead = rhead->next;
		}

		rtail = rhead->next;
		cur = rtail->next;
		while (count < n) {
			ListNode *rnode = cur;
			cur = cur->next;
			rtail->next = rnode->next;
			rnode->next = rhead->next;
			rhead->next = rnode;
			count++;

		}
		head = newhead->next;
		delete newhead;
		return head;
	}
};
