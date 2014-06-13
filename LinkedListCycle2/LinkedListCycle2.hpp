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
    ListNode *detectCycle(ListNode *head) {
        ListNode *lapNode = getOverlapNode(head);
        if (lapNode == NULL) return NULL;
        if (lapNode == head) return head;
        
        while (head != lapNode)
        {
            head = head->next;
            lapNode = lapNode->next;
        }
        return head;
    }
    
    ListNode *getOverlapNode(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *step2node = head;
        ListNode *step1node = head;
        
        while (step2node->next != NULL && step2node->next->next != NULL) {
            step2node = step2node->next->next;
            step1node = step1node->next;
            
            if (step1node == step2node)  return step1node;
        }
        if (step2node->next == NULL || step2node->next->next == NULL)
            return NULL;
        
    }
    
};