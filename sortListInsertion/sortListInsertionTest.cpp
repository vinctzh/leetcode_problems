#include "sortListInsertion.h"
#include <time.h>
using namespace std;

int main()
{
	ListNode *pHead = new ListNode(1);

	ListNode *node = new ListNode(1);

	node->next = NULL;
	pHead->next = node;

	ListNode *node2 = new ListNode(4);
	node->next = node2;
	clock_t start,end;
	start = clock();
	Solution s;
	pHead = s.insertionSortList_2(pHead);
	end = clock();
	cout<<(end-start)<<endl;
	
	ListNode *test = pHead;
	cout<<test->val;
	test = test->next;
	cout<<test->val;
	test = test->next;
	cout<<test->val;


	return 0;
}