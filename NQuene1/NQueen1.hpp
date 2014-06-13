/*
	The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard 
	such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.
	Each solution contains a distinct board configuration of the n-queens' placement,
	where 'Q' and '.' both indicate a queen and an empty space respectively.

	Problem link: https://oj.leetcode.com/problems/n-queens/

	Author: Vincent Zhang
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		cols = (int*)malloc(n*sizeof(int));
		this->n = n;
		solveNQueens_rec(0);

		//free(cols);
		return sols;
	}

	void solveNQueens_rec(int qId) {
		if (qId >= n) {
			vector<string> sol;
			for (int i=0;i<n;i++) {
				string s(n,'.');
				s[cols[i]] = 'Q';
				sol.push_back(s);
				cout<<s<<endl;
			}
			cout<<endl;
			sols.push_back(sol);
		}
		else {
			for (int i=0;i<n;i++) {
				cols[qId] = i;
				if (validHere(qId))  
					solveNQueens_rec(qId+1);
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
	vector<vector<string>> sols;
	int *cols;
	int n;
};


