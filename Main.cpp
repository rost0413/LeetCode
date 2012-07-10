#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "Partition_List.cpp"
using namespace std;

int main() {
	Solution s;
	ListNode *head;
	ListNode *result;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	result = s.partition(head, 0);
	while (result != NULL) {
		cout << result->val << endl;
		result = result->next;
	}

	return 0;
}
