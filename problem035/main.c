#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "takamina.h"




int _isPrime(int* perm, int len);
int hasBadDigit(unsigned num);
int checkCircularity(unsigned num);
unsigned solve(unsigned limit);

int main(){
	clock_t timer = clock();
	printf("Project Euler | Problem 35 | Circular Primes\n");
	
	unsigned limit = 1000000;
	unsigned rs = solve(limit);
	printf("solve(%u) = %d\n", limit,rs);

	printf("sys (%5f s)\n", (double)(clock() - timer)/CLOCKS_PER_SEC);
	return 0;
}


unsigned solve(unsigned limit){
	int count = 2;	 /* counting 2 and 5 before hand, so that hasBadDigit() can exlude 2 and 5 */

	unsigned i;
	for( i = 2; i < limit; ++i){
		if( isPrime(i) ){
			if( hasBadDigit(i) ) {
				continue;
			}
			if( checkCircularity(i) ){
				++count;
			}
		}
	}
	return count;
}

/* forum found cirulation alogorithm */
int checkCircularity (unsigned num){
	int len2 = numDigits_unsigned(num);
	unsigned mag = magnitude_unsigned(num);
	int cnt = 0;
	unsigned num2 = num;
	for( cnt = 0; cnt <len2 ; ++cnt){

		if( !isPrime(num2) ){
			return 0;
		}
		num2 = num2/10 + (num2%10)*(mag);	
	}

	return 1;
}


/* my solution*/
int checkCircularity2(unsigned num ){
	int len = numDigits_unsigned(num);
	int set[len];
	int i =len -1;
	unsigned temp = num;
	/* Create the set */
	do{
		set[i--]= temp%10;
		temp = temp/10;
	}while(temp);

	
	/* walk through each ciruclation */
	int perm[len];
	int permpos = 0;
	int count = 0;
	int setpos = 0;
	for( i = 0; i < len ;++i){

		count = 0;
		permpos = 0;
		setpos = i;
		while( count < len){
			perm[permpos++] = set[setpos++];
			setpos = setpos%len;
			++count;
		}

		/*check to see if this permutaition is Prime */
		if( !_isPrime(perm, len) ){
			return 0;
		}
	}
	return 1;
}





int hasBadDigit(unsigned num){
	static int not_valid_digits[6] = {0,2,4,5,6,8};
	int i;
	do {
		for( i = 0; i < 5; ++i){
			if( num%10 == not_valid_digits[i] ){
				return 1;
			}
		}	
		num = num/10;
	}while( num);
	return 0;
}

int _isPrime(int* perm, int len){
	unsigned num =0;
	unsigned power = 1;
	int i;

	for( i = len-1; i >= 0 ; --i){
		num += perm[i] * power;
		power = power*10;
	}
	return isPrime(num);
}


