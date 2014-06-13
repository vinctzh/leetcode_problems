#include "BuildTree_in_post.h"


int main(){
	vector<int> pOrder;
	/*pOrder.push_back(4);
	*/
	
	pOrder.push_back(1);
	pOrder.push_back(3);
	pOrder.push_back(2);
	vector<int> iOrder;
	/*iOrder.push_back(4);*/
	iOrder.push_back(3);*
	iOrder.push_back(2);
	iOrder.push_back(1);
	
	Solution solu ;
	solu.buildTree(pOrder,iOrder);

	return 0;

}