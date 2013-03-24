#include <stdio.h>
#include <time.h>

int factorial(int n);
int solve();

int main(){
	printf("Project Euler | Problem 34 | Digit Factorials\n");
	clock_t timer = clock();

	int rs = solve();
	printf("solve()=%d\n",rs);


	printf("sys (%5f s)\n", (double)(clock() - timer)/CLOCKS_PER_SEC);
	return 0;
}


int solve(){
	unsigned factorials[10] = {
			factorial(0),
			factorial(1),
			factorial(2),
			factorial(3),
			factorial(4),
			factorial(5),
			factorial(6),
			factorial(7),
			factorial(8),
			factorial(9),
	};

	/*
	 *  the upper bound is 9 999 999.
	 *  Notice     for 99 999 999 =  8x9! =  2 903 040
	 *  which means that for any 8 digit number ( 10 000 000 -> 99 999 999),
	 *  it will always be bigger than the maximum factorial sum.
	 */
	unsigned limit =9999999;
	int sum =0;

	unsigned curr_sum;
	unsigned n;
	unsigned i;

	for( i = 3; i <=limit; ++i){


		/* find the factorial digit sum of this number */
		n = i;
		curr_sum = 0;
		do{
			curr_sum += factorials[n%10];
			n = n/10;
		}while(n);



		/* compare the factorial sum with the current number */
		if( curr_sum == i ){
			printf("%d\n",i);
			sum += i;
		}

	}
	return sum;
}


int factorial(int n){
	int fact = 1;
	int i;
	for(i =1; i <=n; ++i){
		fact = fact*i;
	}	
	return fact;
}
