#include <stdio.h>
#include <time.h>
#include <math.h>

#include "bigint.h"

int isPenta(double value);
int isHexa(double value);
double solve();
double solve2();
int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 45 | triangula, pentagonal and hexagonal numbers\n");


	double rs = solve();
	printf("solve() =%f\n",rs);


	printf("sys ( %5f s)\n", (double)(clock() - time)/ CLOCKS_PER_SEC);
	return 0;
}

int isPenta(double value){
	double num = sqrt(1+8*value);
	return( floor(num) == ceil(num)   && fmod((double)num +1, 4)==0 );
}

int isHexa(double value){
	double num = sqrt(1+ 24*value);
	return (floor(num) == ceil(num) && (fmod((double)num+1,6)==0 ));
}

double solve(){
	int t;
	double num = 0;


	for(t= 286;;++t){
		num = (double)t*(t+1)/2;
		if (isPenta(num)  && isHexa(num) ){
			return  num;
		}
	}
}



double solve2(){
	/* we note that the hexagonal numbers are a subset of the triangular numbers, and
	 * 	as such we incrment by odds */

	int t;
	double num = 1533776805; /* answer*/

	for(t= 287; ;t+=2 ){
		num = sqrt((double)12*t*t + 12*t +1);	
		if( ( floor(num) == ceil(num) ) && fmod((double)num+1,6) == 0 ){
			return (double)t*(t+1)/2;
		}

	}
	printf("\n");
	return 0;
}
