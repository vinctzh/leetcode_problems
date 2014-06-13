#include "Pow.hpp"
#include <math.h>

int main(){
	Solution_Pow solu_pow;
	cout<<(2147483648>>1)<<endl;
	//cout<<solu_pow.pow(2,2147483647)<<endl;
	cout<<std::pow((double)2,(int)2147483647);
	return 0;
}