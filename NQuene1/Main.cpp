#include "NQueen1.hpp"

#include <iostream>
using namespace std;

int n = 4;		// N Queen problem
int cols[4];
int sum = 0;	// ���н�

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
			cols[qId] = i;		// ����qId�ʺ���У���ΪqId
			if (validColume(qId))	// �����һ�����õ����Ƿ�Ϸ�			
				Queen(qId+1);		// ����Ϸ��� �ڷ���һ���ʺ�			
		}
	}
	
	return sum;
}
int main() {
	Solution s;
	s.solveNQueens(1);

	return 0;
}