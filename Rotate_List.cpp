/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 15, 2012
 Problem:    Rotate List
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 Solution:
 O(2n)
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
	ListNode *rotateRight(ListNode *head, int k) {
		int count;
		ListNode *cur, *newtail, *tail;

		if (!head) {
			return head;
		}

		count = 1;
		cur = head;
		while (cur->next) {
			cur = cur->next;
			count++;
		}
		tail = cur;
		k = k % count;

		cur = head;
		count = 0;
		while (count < k) {
			cur = cur->next;
			count++;
		}
		newtail = head;
		while (cur->next) {
			cur = cur->next;
			newtail = newtail->next;
		}
		tail->next = head;
		head = newtail->next;
		newtail->next = NULL;

		return head;
	}
};
