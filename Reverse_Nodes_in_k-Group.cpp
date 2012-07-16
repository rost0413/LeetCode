/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 15, 2012
 Problem:    Reverse Nodes in k-Group
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return
 its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end
 should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5
 Solution:
 This is another version of reverse linked list II.
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *rhead, *newhead, *rtail, *cur;
		int num = 0;

		/* create an empty head to make the operation easier */
		rhead = new ListNode(1);
		rhead->next = head;
		newhead = rhead;

		/* count the total nodes number */
		while (head) {
			num++;
			head = head->next;
		}

		/* reverse in group */
		head = rhead->next;
		num /= k;
		while (num) {
			rtail = rhead->next;
			cur = rtail->next;
			for (int i = 1; i < k; i++) {
				ListNode *rnode = cur;
				cur = cur->next;
				rtail->next = rnode->next;
				rnode->next = rhead->next;
				rhead->next = rnode;
			}
			rhead = rtail;
			num--;
		}

		head = newhead->next;
		delete newhead;
		return head;
	}
};
