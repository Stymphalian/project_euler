#include <stdio.h>
#include <time.h>

int solve(int limit);

int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 39 | Triangle Perimeter Maximizing\n");


	int limit = 1000;
	int rs = solve(limit);
	printf("solve()=%d\n", rs);


	printf("sys (%5f s)\n", (double)(clock() - time)/CLOCKS_PER_SEC);
	return 0;
}

int solve(int limit){

	int p=0;
	int count=0;
	int max= 0;
	int i,a,b;

	for( i = 1; i <= limit ;++i){
		for( a = 1; a < i; ++a){
			for( b = 1; b < i-a; ++b){
				if( 2*a*i + 2*b*i + 2*a*b == i*i){
					++count;
				}
			}
		}
		count = count/2;
		if( count > max){
			max = count;
			p = i;
		}
	}
	return p;
}

