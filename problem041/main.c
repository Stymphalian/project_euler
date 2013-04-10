#include <stdio.h>
#include <time.h>
#include "takamina.h"

unsigned solve();
int main(){
	clock_t time = clock();
	printf("Projet Euler | Problem 40 | Pandigital Prime \n");


	unsigned rs = solve();
	printf("solve()= %u\n", rs);


	printf("sys ( %5f s)\n", (double)( clock() - time) / CLOCKS_PER_SEC);
	return 0;
}

unsigned solve(){

	unsigned i,j;
	unsigned limit = 9999999;

	for(i = limit; i >= 0; i = i/10){
		int len = my_numDigits_int(i);
	
		printf("------------------------\n");
		for( j = i; j >= i/10; j -= 2){
			if( my_isPandigital_n_to_m(1,len,j)){
				printf("%d\n",j);
				if( my_isPrime(j) ){
					return j;
				}

			}
		}
	}
	return 0;
}	
