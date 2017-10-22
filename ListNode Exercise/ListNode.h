//A Small Exercise of linked list
//By 78ij
#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
using namespace std;
//the ListNode struct
struct ListNode{
	int value = 0;
	ListNode *next = nullptr;
};

//Print the List with "->" between values
//head:a pointer pointing at the first ListNode 
void PrintList(ListNode *head){
	for (; head != nullptr; head = head->next) {
		cout << head->value;
		if (head -> next != nullptr)
			cout << " -> ";
	}
}
//Create a linked list
//head:a pointer pointing at the first ListNode
//type 0 to finish Creating the list
void NewList(ListNode *head) {
	int tempvalue;
	cin >> tempvalue;
	if (tempvalue == 0)
		return;
	head->value = tempvalue;
	while (cin >> tempvalue) {
		if (tempvalue != 0) {
			head->next = new ListNode;
			head = head->next;
			head->value = tempvalue;
		}
		else {
			head->next = nullptr;
			break;
		}
	}
}
//Reverse the List
//head:a pointer pointing at the First ListNode
ListNode *ReverseList(ListNode *head) {
	ListNode *save1 = head;
	if (head->next) {
		ListNode *save2 = head->next;
		if (head->next->next)
			ListNode *save3 = head->next->next;
		else {
			head->next->next = head;
			head->next = nullptr;
			head = save2;
			return head;
		}
	}
	else {
		return head;
	}
	ListNode *save2 = head->next;
	ListNode *save3 = head->next->next;
	head = nullptr;
	save1->next = nullptr;
	while(save2 != nullptr){
		save2->next = save1;
		save1 = save2;
		save2 = save3;
		if(save3!=nullptr)
		    save3 = save3->next;
	}
	return save1;
	
}
//Acquire a pointer pointing at a certain ListNode
//head:a pointer pointing at the first ListNode
//number:the position of the required ListNode,starting from 0
//example:in the list"1-2-3-4-5-6",call the function using number = 1 ,and it will return a pointer pointing at ListNode "2"
//undefined call of the function will result in returning a nullptr
ListNode* SelectNode(ListNode *head, int number) {
	for (int i = 0; i < number; i++) {
		if (head != nullptr)
			head = head->next;
		else
			return nullptr;
	}
	return head;
}
//Insert a ListNode containing a certain value to the selected position
//head:a pointer pointing at the first ListNode
//number:the position of the required ListNode,starting from 0
//the inserted Node will be placed in the next position of the Selected ListNode
//example:in the list"1-2-3-4-5-6",call the function with number = 1,value = 6 will make the list this:"1-2-6-3-4-5-6"
//undefined call will result in the function doing nothing and returns
void InsertNode(ListNode *head, int number, int value) {
	head = SelectNode(head, number);
	if (head != nullptr) {
		ListNode *temp = head->next;
		head->next = new ListNode;
		head->next->value = value;
		head->next->next = temp;
	}
	else
		return;
}
//Delete Selected ListNode
//head:a pointer pointing at the first ListNode
//number:the position of the required ListNode,starting from 0
//example:in the list"1-2-3-4-5-6",call the function with number = 2 will make the list this:"1-2-4-5-6"
ListNode *deleteNode(ListNode *head, int number) {
	if (number == 0) {
		ListNode *save = head;
		head = head->next;
		delete save;
		return head;
	}
	else if(SelectNode(head,number) == nullptr){
		return nullptr;
	}
	else if(SelectNode(head,number)->next == nullptr){
		ListNode *save = SelectNode(head, number - 1);
		delete SelectNode(head, number);
		save->next = nullptr;
		return head;
	}
	else {
		ListNode *save1 = SelectNode(head, number - 1);
		ListNode *save2 = SelectNode(head, number);
		save1->next = save2->next;
		delete save2;
		return head;
	}
}
#endif
