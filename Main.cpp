#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include "Rotate_List.cpp"
using namespace std;

ListNode *head, *tail;

void insert(int x) {
	if (!head) {
		head = new ListNode(x);
		tail = head;
	} else {
		tail->next = new ListNode(x);
		tail = tail->next;
	}
}
int main() {
	Solution s;
	ListNode *result;
	head = NULL;
	tail = NULL;

	for (int i = 1; i <= 2; i++) {
		insert(i);
	}
	result = s.rotateRight(head, 13);
	while (result) {
		cout << result->val;
		result = result->next;
	}

	return 0;
}
