/**
	Author: Vincent Zhang
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *sortList(ListNode *head){
        if (head == NULL)
            return head;
        else if (head->next == NULL) 
            return head;
        
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        
        fast = sortList(head);
        slow = sortList(slow);
        
        return mergeList(fast,slow);
        
    }
    ListNode* mergeList(ListNode* list1Head, ListNode* list2Head){
        if (list1Head == NULL) return list2Head;
        if (list2Head == NULL) return list1Head;
        
        ListNode* result, *temp;
        // initialize the first node of the merged result list
        if (list1Head->val < list2Head->val){
            result = list1Head;
            list1Head = list1Head->next;
        }
        else
        {
            result = list2Head;
            list2Head = list2Head->next;
        }
        // operate the result list with temp
        temp = result;
        // end merge if at least one of the two lists reaches the tail node
        while (list1Head != NULL && list2Head != NULL){
            if (list1Head->val < list2Head->val){
                temp->next = list1Head;
                list1Head = list1Head->next;
            }
            else{
                temp->next = list2Head;
                list2Head = list2Head->next;
            }
			temp = temp->next;
        }
        
        if (list1Head != NULL)
            temp->next = list1Head;
        else
            temp->next = list2Head;
            
        return result;
    }
};