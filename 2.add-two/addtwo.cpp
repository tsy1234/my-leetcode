/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int rest = 0;
    	ListNode *head = new ListNode;
    	head -> val = -1;
    	head -> next = NULL;
    	ListNode * list = head;
    	// cout << "once" << endl; 

		while ((l1 -> next) != NULL || (l2 -> next) != NULL) {
			int x = 0, y = 0;

			if ((l1 -> next) != NULL) {
				l1 = l1 -> next;
				x = l1 -> val;
			} 
			if ((l2 -> next) != NULL) {
				l2 = l2 -> next;
				y = l2 -> val;
			} 
			int result = x + y + rest;

			rest = result / 10;
			result = result % 10;

			ListNode* node = new ListNode;
			node -> val = result;
			node -> next = NULL;
			list -> next = node;
			list = list -> next;
		} 

		if (rest > 0) {
			ListNode* node = new ListNode;
			node -> val = rest;
			node -> next = NULL;
			list -> next = node;
			list = list -> next;
		}

		return head;
    }
};

int main(int argc, char const *argv[])
{	
	ListNode lhead;
	ListNode l1;
	ListNode l2;
	ListNode l3;

	l1.val = 3;
	l2.val = 1;
	l3.val = 5;
	lhead.next = NULL;
	l1.next = NULL;
	l2.next = NULL;
	l3.next = NULL;
	lhead.next = &l1;
	l1.next = &l2;
	l2.next = &l3;

	ListNode rhead;
	ListNode r1;
	ListNode r2;
	ListNode r3;

	r1.val = 1;
	r2.val = 9;
	r3.val = 7;
	rhead.next = &r1;
	r1.next = NULL;
	r2.next = NULL;
	r3.next = NULL;
	r1.next = &r2;
	// r2.next = &r3;

	Solution solu;
	ListNode* result = solu.addTwoNumbers(&lhead, &rhead);

	while ((result -> next) != NULL) {
		result = result -> next;
		cout << result -> val << endl;
	}

	return 0;
}