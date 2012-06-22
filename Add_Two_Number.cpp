/*
Author:  Weixian Zhou, ideazwx@gmail.com
Date:    June 22, 2012
Problem: Add Two Number
Difficulty: easy
Source:  http://www.leetcode.com/onlinejudge
Notes:
You are given two linked lists representing two non-negative
numbers. The digits are stored in reverse order and each of
their nodes contain a single digit. Add the two numbers and
return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    struct ListNode *head;
    struct ListNode *tail;
public:
    void insert_new_node(int val) {
        ListNode *node = new struct ListNode(val);
        node->next = NULL;
        if (head == NULL) {
            head = node;
        }
        if (tail == NULL) {
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    void increase_carry(int &sum, int& carry) {
        if (sum > 9) {
            carry = 1;
            sum = sum % 10;
        }
        else {
            carry = 0;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string a;
        string b;
        int sum;
        int carry = 0;

        head = NULL;
        tail = NULL;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            increase_carry(sum, carry);
            insert_new_node(sum);
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            sum = l1->val + carry;
            increase_carry(sum, carry);
            insert_new_node(sum);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            sum = l2->val + carry;
            increase_carry(sum, carry);
            insert_new_node(sum);
            l2 = l2->next;
        }

        if (carry != 0) {
            insert_new_node(carry);
        }

        return head;
    }
};




