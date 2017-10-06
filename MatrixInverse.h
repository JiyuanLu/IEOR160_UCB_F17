#define N 10
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double astar[N][N];
double inverse[N][N];
#define false 0
#define true 1
#define Bool int
void init(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			astar[i][j] = 0.0;
			inverse[i][j] = 0.0;
		}
	}
}
			
double GetDeterminant(double matrix[N][N],int n){
	if(n==1)
		return matrix[0][0];
	double determinant = 0;
	double temp[N][N] = {0.0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			for(int k = 0; k < n-1; k++){
				temp[j][k] = matrix[j+1][(k>=i)?k+1:k];
			}
		}
		double t = GetDeterminant(temp,n-1);
		if(i%2==0)
			determinant += matrix[0][i]*t;
		else
			determinant -= matrix[0][i]*t;
	}
	return determinant;
}

void GetAStar(double matrix[N][N],int n){
	if(n==1)
		astar[0][0] = 1;
	double temp[N][N] = {0.0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
	 		for(int k = 0; k < n - 1; k++){
				for(int t = 0; t < n - 1; t++){	
					temp[k][t] = matrix[k>=i?k+1:k][t>=j?t+1:t];
			if((i+j)%2 == 0)
				astar[j][i] = GetDeterminant(temp,n-1);
			else
				astar[j][i] = - GetDeterminant(temp,n-1);
				}
			}
		}
	}
}

Bool GetInverse(double matrix[N][N], int n){
	init();
	double det = GetDeterminant(matrix,n);
	if(abs(det) < 1e-10){
		printf("uninvertible matrix!\n");
		return false;
	}
	GetAStar(matrix, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			inverse[i][j] = astar[i][j] / det;
			//printf("%.2lf\t",inverse[i][j]);
		}
		//printf("\n");
	}
	return true;
}

