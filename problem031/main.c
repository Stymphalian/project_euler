#include <stdio.h>
#include <time.h>

int solve(int width);
int main(){
	printf("Project Euler: Problem 31 : Coin sums\n");
	clock_t time = clock();

	int width = 200;
	int rs = solve(width);
	printf("solve() = %d\n", rs);

	printf("sys ( %5f s)\n", (double)(clock() -time)/CLOCKS_PER_SEC);
	return 0;
}



int solve(int width)
{
	int len = 8;
	int coins[9] = {
		1,2,5,10,20,50,100,200
	};
	int array[width +1];
	int i,j;
	for( i = 0; i < width+1; ++i){
		array[i] = 0;
	}	
	array[0] = 1;

	for( i = 0; i < len; ++i){
		for( j =coins[i]; j <= width; ++j ){
			array[j] = array[j] + array[j - coins[i]];
		}
		
	}
	return array[width];
}


