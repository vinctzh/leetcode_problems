#include "Utils.h"

class Solution_Pow {
public:
	double pow(double x, int n) {

		if (n < 0 && abs(x-0.0)<0.0000001)
			return -1;

		if (abs(x-1.0)<0.0000001){
			return x;
		}

		int abs_n = abs(n);
		double result = powUnsigned(x,abs_n);
		if (n<0)
			result = 1 / result;
		return result;
	}

private:
	double power(double x, int n)
	{
		if (n == 0)
			return 1;

		double v = power(x, n / 2);

		if (n % 2 == 0)
			return v * v;
		else
			return v * v * x;
	}


	// program stack overlaps when n is a large number
	double powUnsigned_Rec(double x, int n){
		if (n == 0) return 1;
		if (n == 1) return x;

		double result = powUnsigned_Rec(x,n>>1);
		result *= result;

		if (n&1 == 1) result *= x;

		return result;
	}
	double powUnsigned(double x, int n){
		if (n == 0) return 1;
		if (n == 1) return x;
		
		double result = x*x;
		int even_n = n & -2;

		for (int i=2;i<even_n ;i*=2){
			cout<<i<<endl;;
			result *=result;
		}


		if (n&1) result *= x;

		return result;
	}
};