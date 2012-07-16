/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 12, 2012
 Problem:    Remove Duplicates from Sorted List
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a sorted linked list, delete all duplicates such that each element
 appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *pre = NULL, *cur = head;
		while (cur != NULL) {
			if (pre != NULL && cur->val == pre->val) {
				pre->next = cur->next;
			} else {
				pre = cur;
			}
			cur = cur->next;
		}
		return head;
	}
};
