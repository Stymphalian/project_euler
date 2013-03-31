#include <stdio.h>
#include <time.h>

int isPrime(unsigned num);
int isLeftTruncPrime(unsigned num);
int isRightTruncPrime(unsigned num);
int solve(int limit);

int main(){
	clock_t time = clock();
	printf("Project Euler |  Problem 37 | Truncatable Primes\n");


	int limit = 11;
	int rs = solve(limit);
	printf("solve(%d)= %d\n", limit, rs);

	printf("sys (%5f s )\n", (double)(clock() - time) / CLOCKS_PER_SEC);
	return 0;
}




int solve(int limit){
	int count=0;
	int sum = 0;
	unsigned i ;

	for(i=10; count < limit ;++i){
		if(isLeftTruncPrime(i) && isRightTruncPrime(i)){
			++count;
			sum += i;
			printf("%d\n", i);
		}
	}
	return sum;	
}

int isPrime(unsigned num){
	if( num ==2 ){return 1;}
	if( num == 1){return 0;}
	if( (num&1) == 0) { return  0;}

	unsigned i = 0;
	for ( i= 3; i*i <= num; i += 2){
		if( num%i == 0){return 0;}
	}
	return 1;
}

int isRightTruncPrime(unsigned num){

	while(num){
		if( !isPrime(num) ){return 0;}
		num  = num/10;
	}
	return 1;
}

int isLeftTruncPrime(unsigned num){
	unsigned mag =1;;	
	while(mag*10 <= num){
		mag = mag*10;
	}

	while(num){
		if(!isPrime(num) ){return 0;}
		num = num - (num/mag)*mag;
		mag = mag/10;
	}
	return 1;
}
