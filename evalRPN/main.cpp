#include <iostream>
#include <string>
#include "evalRPN.hpp"

using namespace std;

int main(){
	Solution_evalRPN ss;
	
	
	vector<string> test;
	test.push_back("4");
	test.push_back("13");
	test.push_back("5");
	test.push_back("/");
	test.push_back("+");

	cout<<ss.evalRPN(test);

	return 0;
}