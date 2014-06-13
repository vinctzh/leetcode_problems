/*
	The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard 
	such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.
	Each solution contains a distinct board configuration of the n-queens' placement,
	where 'Q' and '.' both indicate a queen and an empty space respectively.

	Problem link: https://oj.leetcode.com/problems/n-queens-ii/

	Author: Vincent Zhang
*/
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
	int totalNQueens(int n) {
		cols = (int*)malloc(n*sizeof(int));
		this->n = n;
		sum = 0;
		solveNQueens_rec(0);
		return sum;
	}
	void solveNQueens_rec(int qId) {
		if (qId >= n) {
			sum++;
		}
		else {
			for (int i=0;i<n;i++) {
				cols[qId] = i;
				if (validHere(qId))  solveNQueens_rec(qId+1);
			}
		}
	}

	bool validHere(int qId) {
		for (int i=0;i<qId;i++) {
			if ( cols[i] == cols[qId] || (abs(cols[i]-cols[qId]) == abs(i-qId)) )
				return false;
		}
		return true;
	}

private:
	int *cols;
	int n;
	int sum;
};