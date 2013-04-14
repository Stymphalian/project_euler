#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "takamina.h"

int meetsConditions(int* perm, int permlen);
int callback(int* perm, int permlen, void* object);
double solve();
int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 43 |  Special Pandigital Numbers \n");
			

	double rs = solve();
	printf("solve() = %f\n", rs);


	printf("sys ( %5f s ) \n", (double)(clock() - time)/CLOCKS_PER_SEC);
	return 0;
}


double solve(){
	double sum = 0;
	int digits[10] = {0,1,2,3,4,5,6,7,8,9};
	my_permutations(digits, 10, 10, &sum,&callback); /* permutations of 0-9 guarantees pandigitalness */
	return sum;
}

int callback(int* permutation, int permlen, void* object){
	if( meetsConditions(permutation, permlen) ){
		char str[10+1];
		int i = 0;
		for( i = 0; i < permlen; ++i){
			str[i] = permutation[i] + '0';
		}
		str[10] = '\0';


		*((double*)object)+= atof(str);
	}
	return 1;
}
int meetsConditions(int* permutation, int permlen){
	static int divisors[7] = {2,3,5,7,11,13,17};

	int i;
	int num = 0;

	for( i = 1; i <= 7; ++i){
		num = permutation[i]*100 + permutation[i+1]*10 + permutation[i+2];
		if( num % divisors[i-1] != 0 ){
			return 0;
		}
	}
	return 1;
}
