/*
	Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules:http://sudoku.com.au/TheRules.aspx.
	The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
	Note:
	A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

	Copyright ©2014 Vincent Zhang 
	Blog: http://www.centvin.com 
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int row=0; row< BOARD_SIZE; row++) {
			for (int col=0; col<BOARD_SIZE; col++) {
				if (board[row][col] != '.') {
					if (!isValid(board, row, col))
						return false;
				}
			}
		}
		return true;
	}
private:
	bool isValid(vector<vector<char> > &board, int row, int col) {
		char curChar = board[row][col];
		// check the row and col
		for (int i=0;i<BOARD_SIZE;i++) {
			if (curChar == board[row][i] && i != col)		// row check
				return false;
			if (curChar == board[i][col] && i != row)		// col check
				return false;
		}
		// check the sub block
		int blockStartRow = (row / 3)*3;
		int blockStartCol = (col / 3)*3;

		for (int i=blockStartRow;i<blockStartRow+3;i++) {
			for (int j=blockStartCol; j<blockStartCol+3; j++) {
				if (curChar == board[i][j] && i != row && j != col) {
					cout<<i<<" "<<j<<" "<<board[i][j]<<" "<<curChar<<endl;
					return false;
				}
			}
		}
		return true;
	}
	static const int BOARD_SIZE = 9;
	static const int BLOCK_SIZE = 3;
};
//
//vc[0][2] = '5';
//vc[0][8] = '6';
//
//vc[1][4] = '1';
//vc[1][5] = '4';
//
//vc[3][5] = '9';
//vc[3][6] = '2';
//
//vc[4][0] = '5';
//vc[4][5] = '2';
//
//vc[5][7] = '3';	
//
//vc[6][3] = '5';
//vc[6][4] = '4';	
//
//vc[7][0] = '3';
//vc[7][6] = '4';
//vc[7][7] = '2';
//
//vc[8][3] = '2';
//vc[8][4] = '7';
//vc[8][6] = '6';