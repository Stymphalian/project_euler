#include <stdio.h>
#include <time.h>

int solve();
int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 46 | Goldbach's Other Conjecture\n");


	int rs = solve();
	printf("solve() = %d\n", rs);


	printf("sys (%5f s)\n", (double)(clock() - time)/ CLOCKS_PER_SEC);
	return 0;
}

int solve(){
	return 0;
}
