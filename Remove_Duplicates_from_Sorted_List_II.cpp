/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 12, 2012
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 Solution:
 Altought the problem is straight forward, I spend hours in order to write
 elegant codes. Too often complex codes mean mess logic.
 In this problem, there are many ways to delete the duplicates. But where
 to do all the operations, on the original list or open a new list? I tried
 the first but found the code becomes messy and my logic becomes chaos.
 Then I open a new list, the operations become clear and my logic is straight.
 And how to choose the end condition of the loop? head != NULL or
 head->next != NULL. I found when I choose head->next != NULL, the code becomes
 complex. But when I use head != NULL, the code becomes clear.
 So the logic before coding is most important, it decides whether your code
 is elegant or chaos.
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
		ListNode *new_head = NULL;
		ListNode *new_tail = NULL;

		while (head != NULL) {
			int count = 1;
			while (head->next != NULL && head->val == head->next->val) {
				head = head->next;
				count++;
			}
			if (count == 1) {
				if (new_head == NULL) {
					new_head = new_tail = head;
				} else {
					new_tail->next = head;
					new_tail = head;
				}
			}
			head = head->next;
		}
		if (new_tail != NULL) {
			new_tail->next = NULL;
		}
		return new_head;
	}
};
