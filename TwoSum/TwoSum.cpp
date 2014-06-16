#include "TwoSum.hpp"

int main() {
	
	Solution sl;
	vector<int> test;
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	test.push_back(15);
	vector<int> rst = sl.twoSum(test,19);
	cout<<rst.size()<<endl;
	cout<<test[rst[0]-1]<<"  "<<test[rst[1]-1]<<endl;
	return 0;
}