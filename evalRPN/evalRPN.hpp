#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_evalRPN {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> token_stack;
		
		int count = tokens.size();
		if (count == 1)		
			return atoi(tokens[0].c_str());
		int result = 0;
		for (int i=0;i<count;i++)
		{
			if (!isOperator(tokens[i]))
			{
				token_stack.push(atoi(tokens[i].c_str()));
			}				
			else
			{
				if (!token_stack.empty())
				{
					if (token_stack.size() == 1)
					{
						result = doOperator(tokens[i],token_stack.top(),result);
						token_stack.pop();
					}
					else
					{
						int b = token_stack.top(); token_stack.pop();
						int a = token_stack.top(); token_stack.pop();
						result = doOperator(tokens[i],b,a);	
					}
					token_stack.push(result);
				}
			}

		}
				
		return result;
	}
	int doOperator(string token,int b,int a)
	{
		cout<<a<<token<<b<<endl;
		if (token.compare("+")==0)
			return a+b;
		if (token.compare("-")==0)
			return a-b;
		if (token.compare("*")==0)
			return a*b;
		if (token.compare("/")==0)
			return a/b;
	}
	bool isOperator(string token)
	{		
		if (token.compare("+")==0 || token.compare("-")==0 || token.compare("*")==0  || token.compare("/")==0)
			return true;		
		return false;
	}
};