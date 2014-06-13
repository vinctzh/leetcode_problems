#include "sortList.hpp"

using namespace std;

int main()
{
	ListNode *pHead = new ListNode(3);

	ListNode *node = new ListNode(2);
	
	node->next = NULL;
	pHead->next = node;

	ListNode *node2 = new ListNode(4);
	node->next = node2;

	Solution s;
	pHead = s.sortList(pHead);

	ListNode *test = pHead;
	cout<<test->val;
	test = test->next;
	cout<<test->val;
	test = test->next;
	cout<<test->val;
	

	return 0;
}