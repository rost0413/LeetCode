/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 13, 2012
 Problem:    Remove Nth Node From End of List
 Difficulty:
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a linked list, remove the nth node from the end of list and return its
 head.

 For example,

 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution:
 Again, the way you think decides the quality of codes. My first idea is N-step:
 count the steps when traverse and mark the node at every n step. When reach the
 end of the list, there are two situations: 1) the count less than n, say m,
 it means you start traverse from the previous mark and count m and find the
 target node; 2) the count is equal to n, then the marked node is the target node.
 But the above method is a liitle complex to implement. In order to delete the
 target node, you have to have the pointer of its previous node. It adds additional
 variable and boundry condition checking. It is not what I like.
 There is always better solution.
 Here we only need two pointers. First traverse the list and stop at n steps from
 the head, now the first pointers is at the nth node. Then move forward both two
 pointers until the first pointer reach the end. Now the second point is exactly
 n steps away from the end. Now the code is clear!
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *prior = head, *post = head;
		int count = 0;

		while (prior != NULL && count < n) {
			count++;
			prior = prior->next;
		}
		if (prior == NULL) {
			return head->next;
		}
		while (prior->next != NULL) {
			prior = prior->next;
			post = post->next;
		}
		post->next = post->next->next;
		return head;
	}
};
