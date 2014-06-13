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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode *step2node = head;
        ListNode *step1node = head;
        
        while (step2node->next != NULL && step2node->next->next != NULL) {
            step2node = step2node->next->next;
            step1node = step1node->next;
            
            if (step1node == step2node)  return true;
        }
        
        return false;
    }
};