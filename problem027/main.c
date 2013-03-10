#include <stdio.h>
#include <math.h>
#include <time.h>


#define fn(a,b,n) n*n + a*n + b
int isPrime(int num);
int solve( int la, int lb);
int main(){
	clock_t time = clock();
	printf("Project Euler : Problem 27 - Quadratic Primes\n");


	int a = 1000;
	int b = 1000;
	int rs = solve(a,b);
	printf("solve(%d,%d) = %d\n", a, b, rs);


	printf("sys (%5f s)\n", (double)(clock() -time) / CLOCKS_PER_SEC );
	return 0;
}


int solve( int la, int lb){
	/* make sure we have +ve values */
	la = ( la < 0 ) ? -la : la;
	lb = ( lb < 0 ) ? -lb : lb;


	int a;
	int b;
	int n;

	int max_a =0;
	int max_b =0;
	int max = 0;
	int count = 0;
	for( a = -la ; a < la ; ++a){

		for( b = -la; b < la ; ++b){

			count =0;
			for(n = 0;1;++n){
				if(!isPrime(fn(a,b,n)) ){
					break;
				}
				++count;
			}
			if( count > max ){
				max = count;
				max_a = a;
				max_b = b;
			}
		}

	}

	printf("n^2 + %d*n + %d= %d\n", max_a,max_b,max);
	return max_a * max_b;
}


int isPrime( int num ){
	num *= ( num < 0 ) ? -1 : 1;
	int i= 0;
	for( i = 2; i < num ; ++i){
		if( num %i == 0){
			return 0;
		}
	}
	return 1;
}
