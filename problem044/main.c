#include<stdio.h>
#include<time.h>
#include <math.h>


#include "takamina.h"

int isPentagonal(unsigned  value);
unsigned fn(int n); 
unsigned gn(int n);
int solve();
int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 44 | Pentagon Number\n");

	int rs = solve();
	printf("solve() = %d\n", rs);


	printf("sys ( %5f s) \n", (double)(clock() - time)/ CLOCKS_PER_SEC);
	return 0;
}


int isPentagonal(unsigned value){
	if(value == 0 ){return 0;}
	double num = sqrt(1 +24*value);
	if ( (floor(num) == ceil(num))  &&  ((unsigned)num +1)%6 == 0  ) {
		return 1;
	}
	return 0;
}


/* determines the nth pentagonal number */
unsigned fn(int n){
	if( n <= 0) { return 0;}
	return ( 3*n*n -n )/2;
}

/* determines the index value of the pentagonal number*/
unsigned gn(int n){
	if( n <= 0 ) {return 0;}

	if( isPentagonal(n)){
		return ((unsigned)(sqrt(1+24*n) - 1) /6 ) +1;
	}
	return 0;
}


int solve(){

	unsigned i ;
	unsigned j ;

	/* I don't know how to determine an upper limit for checking */

	for( i = 1; i < 10000; ++i ){
		for( j = i+1; j < 10000; ++j){
			unsigned nval = fn(i);
			unsigned mval = fn(j);
			if( isPentagonal(nval+mval) && isPentagonal(mval-nval)){
				printf("(%u,%u)=%u\n", i,j, mval - nval);		
			}
		}
	}
	return 0;
}
