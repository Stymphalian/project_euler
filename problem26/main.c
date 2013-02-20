#include <stdio.h>
#include <time.h>

int main(){
	printf("Project Euler: Problem 26\n");
	clock_t time = clock();

	printf("sys ( %5f s)\n", (double)(clock() -time)/CLOCKS_PER_SEC);
	return 0;
}
