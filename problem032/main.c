#include <stdio.h>
#include <time.h>
#include <string.h>


unsigned getMask(unsigned num);
int solve();

int main()
{
	printf("Project Euler | Problem 32 | Pandigital Numbers\n");
	clock_t time = clock();

	int rs = solve();
	printf("sovle() = %d\n", rs);

	printf("sys (%5f s)\n", (double)(clock() - time)/ CLOCKS_PER_SEC);
	return 0;
}


int solve(){


	int max = 10000;
	int array[max];
	memset(array,0, sizeof(int)*max);
	int i,j;
	int sum =0;

	for( i = 1; i <= 99; ++i){
		for( j = 100; j <= 9999; ++j){
			if( i*j > max) {break;}

			if( !array[i*j] ){
				if( 0x1ff == (getMask(i) | getMask(j) | getMask(i*j)) ){
					sum += i*j;
					array[i*j] = i*j;
				}
			}

		}
	}
	return sum;
}


unsigned getMask(unsigned num){
	unsigned d;
	unsigned mask =0;
	do{
		d = num%10;
		mask |= ( 1 << (d-1));
		num = num/10;
	}while(num);
	return mask;
}
