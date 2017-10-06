#include "MatrixInverse.h"
#include <time.h>
#define n 8
int main()
{
	srand(time(NULL));
	double matrix[N][N];
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix[i][j] = ((double)rand()/RAND_MAX) * 1000  ;
	GetInverse(matrix,n);
	return 0;
}
