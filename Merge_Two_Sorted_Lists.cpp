/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 7, 2012
 Problem:    Merge Two Sorted Lists
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Merge two sorted linked lists and return it as a new list. The new list should
 be made by splicing together the nodes of the first two lists.

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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head = NULL;
		ListNode *tail = NULL;
		ListNode **next_list = NULL;

		while (l1 != NULL && l2 != NULL) {
			next_list = (l1->val < l2->val ? &l1 : &l2);
			if (head == NULL) {
				head = *next_list;
				tail = *next_list;
			} else {
				tail->next = *next_list;
				tail = tail->next;
			}
			*next_list = (*next_list)->next;
		}
		next_list = (l1 != NULL ? &l1 : &l2);
		if (next_list != NULL) {
			if (head == NULL) {
				head = *next_list;
			} else {
				tail->next = *next_list;
			}
		}
		return head;
	}
};
