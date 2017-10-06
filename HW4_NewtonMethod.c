#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "MatrixInverse.h"

#define iterations 50
#define alpha 1
#define beta 0.6

/* function */
double f(double x1, double x2){
	return exp(x1-x2-0.4) + exp(x1+x2-0.4) + pow((x1-1),2) + pow((x2+1),2);
}

/* gradient */
double g1(double x1, double x2){
	return exp(x1-x2-0.4) + exp(x1+x2-0.4) + 2 * (x1 - 1);
}

double g2(double x1, double x2){
	return -exp(x1-x2-0.4) + exp(x1+x2-0.4) + 2 * (x2 + 1);
}

/* Hessian */
double h11(double x1, double x2){
	return exp(x1-x2-0.4) + exp(x1+x2-0.4) + 2;
}

double h12(double x1, double x2){
	return -exp(x1-x2-0.4) + exp(x1+x2-0.4);
}

double h21(double x1, double x2){
	return -exp(x1-x2-0.4) + exp(x1+x2-0.4);
}

double h22(double x1, double x2){
	return exp(x1-x2-0.4) + exp(x1+x2-0.4) + 2;
}

int main(){
	/* rand */
	srand(time(NULL));
	double x1 = ((double)rand()/RAND_MAX) , x2 = ((double)rand()/RAND_MAX);
	printf("initial point is (%lf , %lf) \t",x1,x2);
	printf("f = %lf\n",f(x1,x2));
	double step = alpha;
	double oldValue, newValue;
	for(int i=0; i<iterations;i++){
		do{
			double hessian[N][N] = {{h11(x1,x2), h12(x1,x2)}, {h21(x1,x2), h22(x1,x2)}};
			//printf("%lf \t %lf \n %lf %lf \n",hessian[0][0],hessian[0][1],hessian[1][0],hessian[1][1]);
			GetInverse(hessian,2);
			//printf("%lf \t %lf \n %lf %lf \n",inverse[0][0],inverse[0][1],inverse[1][0],inverse[1][1]);
			oldValue = f(x1,x2);
			double temp1 = inverse[0][0] * g1(x1,x2) + inverse[0][1] * g2(x1,x2);
			double temp2 = inverse[1][0] * g1(x1,x2) + inverse[1][1] * g2(x1,x2);
			x1 -= step * temp1;
			x2 -= step * temp2;
			newValue = f(x1,x2);
			step *= beta;
		}while(oldValue <= newValue);
		printf("at iteration %d: ",i+1);
		printf("point:(%lf,%lf)\t",x1,x2);
		printf("f = %lf\n",f(x1,x2));
	}	
	return 0;
}
