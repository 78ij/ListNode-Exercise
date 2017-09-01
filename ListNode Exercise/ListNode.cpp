#include "ListNode.h"
int main() {
	ListNode *head = new ListNode;
	NewList(head);
	PrintList(head);
	cout << "\n";
	head = deleteNode(head, 7);
	PrintList(head);
	getchar();
	getchar();
	return 0;
}
