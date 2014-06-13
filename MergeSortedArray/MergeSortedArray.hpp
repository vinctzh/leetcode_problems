class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int endIndex = m + n - 1;
		while (m>0 && n >0)
		{
			if (A[m-1] > B[n-1])
			{
				A[endIndex] = A[m-1];
				m--;
			}
			else
			{
				A[endIndex] = B[n-1];
				n--;
			}
			endIndex-- ;
		}
		while (m>0)
		{
			A[endIndex] = A[m-1];
			m--;
			endIndex-- ;
		}
		while (n>0)
		{
			A[endIndex] = B[n-1];
			n--;
			endIndex-- ;
		}
	}

};