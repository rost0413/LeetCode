/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 9, 2012
 Problem:    Partition List
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a linked list and a value x, partition it such that all nodes less than
 x come before nodes greater than or equal to x.

 You should preserve the original relative order of the nodes in each of the
 two partitions.

 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 Solution:

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
	ListNode *partition(ListNode *head, int x) {
		ListNode *pre_head = NULL, *pre_tail = NULL;
		ListNode *post_head = NULL, *post_tail = NULL;

		while (head != NULL) {
			if (head->val < x) {
				if (pre_head == NULL) {
					pre_head = head;
					pre_tail = head;
				} else {
					pre_tail->next = head;
					pre_tail = pre_tail->next;
				}
			} else {
				if (post_head == NULL) {
					post_head = head;
					post_tail = head;
				} else {
					post_tail->next = head;
					post_tail = post_tail->next;
				}
			}
			head = head->next;
		}
		if (pre_head != NULL) {
			pre_tail->next = post_head;
		}
		if (post_head != NULL) {
			post_tail->next = NULL;
		}
		return (pre_head != NULL ? pre_head : post_head);
	}
};
