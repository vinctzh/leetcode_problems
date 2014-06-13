/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* merged;
        if (l2->val < l1->val) {
            merged = l2;
            l2 = l2->next;
        }
        else {
            merged = l1;
            l1 = l1->next;
        }
        ListNode *index = merged;
        while (l1 != NULL && l2 != NULL)
        {
            if (l2->val < l1->val) {
                index->next = l2;
                l2 = l2->next;
            }
            else {
                index->next = l1;
                l1 = l1->next;
            }
            index = index->next;
        }
        
        if (l1 != NULL)
            index->next = l1;
        else
            index->next = l2;
        
        return merged;
    }
};