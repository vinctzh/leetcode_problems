/**
	Author: Vincent Zhang
	Problem: https://oj.leetcode.com/problems/insertion-sort-list/
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {

		// check if head is NULL or has no next node, return head
		if (head == NULL || head->next == NULL) return head;

		// pointer point to current node
		ListNode *pCurrent = head->next;
		// set the next node of head to NULL, which break the inputed list into 2 halves;
		// first half begin with head, end with a NULL: the sorted part;
		// second half contains the unsorted nodes.
		head->next = NULL;
		ListNode *pTemp = NULL, *index = NULL;
		// pCurrent is not NULL, meaning not the last node
		while (pCurrent != NULL)
		{   
		    // save the next node of pCurrent to pTemp
		    pTemp = pCurrent->next;
		    // insertion to the head
		    if (pCurrent->val <= head->val)
		    {
		        pCurrent->next = head;
		        head = pCurrent;
		    }
		    else    // Find the proper position to insert
		    {
		        index = head;
		        while (index->next !=NULL && pCurrent->val > index->next->val)
		            index = index->next;
		        pCurrent->next = index->next;
		        index->next = pCurrent;
		    }
		    pCurrent = pTemp;
		}
		return head;
	}
};