#include "NQueen1.hpp"

#include <iostream>
using namespace std;

int n = 4;		// N Queen problem
int cols[4];
int sum = 0;	// 所有解

bool validColume(int qId) {
	for (int i=0; i<qId;i++)
	{
		if (cols[qId] == cols[i] || (abs(qId-i) == abs(cols[qId]-cols[i])))
			return false;
	}
	return true;
}

int Queen(int qId) {
	if (qId >= n) {
		for (int i=0;i<n;i++)
		{
			cout<<cols[i]<<" ";
		}
		cout<<endl;
		sum++;
	}
	else {
		for (int i=0; i<n; i++) {
			cols[qId] = i;		// 设置qId皇后的列，行为qId
			if (validColume(qId))	// 检测上一步设置的列是否合法			
				Queen(qId+1);		// 如果合法， 摆放下一个皇后			
		}
	}
	
	return sum;
}
int main() {
	Solution s;
	s.solveNQueens(1);

	return 0;
}