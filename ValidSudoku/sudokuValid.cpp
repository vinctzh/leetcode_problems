#include "ValidSudoku.hpp"

int main() {
	Solution sl;
	//".87654321","2........","3........","4........","5........","6........","7........","8........","9........"
	//"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."
	vector <vector<char>> vc;
	vector<char> vcc;
	for (int i=0;i<9;i++) {
		vcc.clear();
		for (int j=0;j<9;j++)
		{
			vcc.push_back('.');
		}
		cout<<vcc.size()<<" "<<vc.size()<<endl;
		vc.push_back(vcc);
	}
	cout<<vc.size()<<endl;
	vc[0][1] = '8';
	vc[0][2] = '7';
	vc[0][3] = '6';
	vc[0][4] = '5';
	vc[0][5] = '4';
	vc[0][6] = '3';
	vc[0][7] = '2';
	vc[0][8] = '1';

	vc[1][0] = '2';	
	vc[2][0] = '3';
	vc[3][0] = '4';	
	vc[4][0] = '5';
	vc[5][0] = '6';
	vc[6][0] = '7';
	vc[7][0] = '8';
	vc[8][0] = '9';





	cout<<endl<<"result is "<< sl.isValidSudoku(vc);
	return 0;
}