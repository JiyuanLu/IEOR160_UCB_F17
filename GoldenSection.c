#include <stdio.h>
#include <math.h>

# define r 0.6180339887

double f(double x){
	return x - 2 * exp(x);
}

int main(int argc, char* argv[]){
	printf("input start, end, precision\n");
	double a,b,p;
	scanf("%lf%lf%lf",&a,&b,&p);
	// f(x) = x - 2e^x	value function
	double len = b - a;
	double x2 = a + r * len;
	double x1 = b - r * len;
	while(p < len){
		if(f(x1) >= f(x2)){	// optimal section before x2
			b = x2;
			double temp = x1;
			x1 = b - r * (b-a);
			x2 = temp;
		}
		else{			// optimal section after x1
			a = x1;
			double temp = x2;
			x2 = a + r * (b-a);
			x1 = temp;
		}
		len = b - a;
	}
	printf("optimal solution x1 is %.2lf with f(%.2lf) = %.2lf\n", x1,x1,f(x1));
	printf("optimal solution x2 is %.2lf with f(%.2lf) = %.2lf\n", x2,x2,f(x2));
	return 0;
}
		 


