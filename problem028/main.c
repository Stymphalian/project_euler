#include <stdio.h>
#include <time.h>

int solve(int width);
int main() {
	printf("Project Euler 28:\n");
	clock_t time = clock();


	int width = 1001;
	int rs = solve(width);
	printf("solve(%d) = %d\n", width,rs);

	printf("sys (%5f s)\n",(double)(clock() - time)/CLOCKS_PER_SEC);
	return 0;
}


int solve(int width){
	int limit = width*width;

	int sum =1;


	int i;
	int step = 2;
	int count =0;
	for ( i = 3 ; i <= limit; i+=step ){
		sum += i;	
		++count;	
		if(count%4 == 0 ){
			count = 0;
			step = step + 2;
		}
	}
	return sum;
}
