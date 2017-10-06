#include <stdio.h>
#include <math.h>

double function(double x1,double x2){
	return pow((x1-x2),2) + exp(-x1-x2) + x1 + x2;
}

int main(){
	double x1,x2;
	
	while(1){
		scanf("%lf %lf",&x1,&x2);
		double ans = function(x1,x2);
		printf("%.2f\n",ans);
	}
	
	double ans = 0.9 + 1/10 * exp(-2);

	printf("%.2f\n",ans);
	return 0;
}
