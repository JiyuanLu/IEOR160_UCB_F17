#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

int main(){
	/* rand */
	srand(time(NULL));
	double x1 = ((double)rand()/RAND_MAX) , x2 = ((double)rand()/RAND_MAX);
	printf("initial point is (%lf , %lf) \t",x1,x2);
	printf("f = %lf\n",f(x1,x2));
	for(int i=0; i<iterations;i++){
		double oldValue, newValue;
		double step = alpha;
		double t1, t2;
		oldValue = f(x1,x2);
		do{
			t1 = x1 - step * g1(x1,x2);
			t2 = x2 - step * g2(x1,x2);
			newValue = f(t1,t2);
			step *= beta;
		}while(newValue > oldValue);
		x1 = t1;
		x2 = t2;
		printf("at iteration %d: ",i+1);
		printf("point:(%lf,%lf)\t",x1,x2);
		printf("f = %lf\n",f(x1,x2));
	}	
	return 0;
}
